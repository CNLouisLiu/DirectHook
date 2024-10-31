#include <dxgi.h>
#include <d3d12.h>
#include "d3d12hook.h"
#include "../method_table.h"

namespace directhook::d3d12
{
    template<typename ComT>
    void SafeRelease(ComT* ptr)
    {
        if (ptr) ptr->Release();
        ptr = nullptr;
    }

	using PFN_CreateDXGIFactory = HRESULT(STDMETHODCALLTYPE*)(REFIID, void**);
	using PFN_CreateD3D12Device = HRESULT(STDMETHODCALLTYPE*)(IUnknown*, D3D_FEATURE_LEVEL, REFIID, void**);

	Status Initialize(MethodTable& methodTable)
	{
		WNDCLASSEX windowClass;
		windowClass.cbSize = sizeof(WNDCLASSEX);
		windowClass.style = CS_HREDRAW | CS_VREDRAW;
		windowClass.lpfnWndProc = DefWindowProc;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;
		windowClass.hInstance = GetModuleHandle(nullptr);
		windowClass.hIcon = nullptr;
		windowClass.hCursor = nullptr;
		windowClass.hbrBackground = nullptr;
		windowClass.lpszMenuName = nullptr;
		windowClass.lpszClassName = L"DirectHook";
		windowClass.hIconSm = nullptr;

		::RegisterClassEx(&windowClass);
		HWND window = ::CreateWindow(windowClass.lpszClassName, L"Window", WS_OVERLAPPEDWINDOW, 0, 0, 100, 100, nullptr, nullptr, windowClass.hInstance, nullptr);

		HMODULE libDXGI = ::GetModuleHandle(L"dxgi.dll");
		HMODULE libD3D12 = ::GetModuleHandle(L"d3d12.dll");
		if (libDXGI == nullptr || libD3D12 == nullptr)
		{
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			return Status::Error_GfxApiInitFailed;
		}

		PFN_CreateDXGIFactory CreateDXGIFactory = (PFN_CreateDXGIFactory)::GetProcAddress(libDXGI, "CreateDXGIFactory");
		if (CreateDXGIFactory == nullptr)
		{
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			return Status::Error_GfxApiInitFailed;
		}

		IDXGIFactory* factory = nullptr;
		if (CreateDXGIFactory(IID_PPV_ARGS(&factory)) != S_OK)
		{
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			return Status::Error_GfxApiInitFailed;
		}

		IDXGIAdapter* adapter = nullptr;
		if (factory->EnumAdapters(0, &adapter) == DXGI_ERROR_NOT_FOUND)
		{
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			return Status::Error_GfxApiInitFailed;
		}

		PFN_CreateD3D12Device D3D12CreateDevice = (PFN_CreateD3D12Device)::GetProcAddress(libD3D12, "D3D12CreateDevice");
		if (D3D12CreateDevice == nullptr)
		{
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			return Status::Error_GfxApiInitFailed;
		}

		ID3D12Device* device = nullptr;
		if (D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device)) != S_OK)
		{
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			return Status::Error_GfxApiInitFailed;
		}

		D3D12_COMMAND_QUEUE_DESC queueDesc{};
		queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
		queueDesc.Priority = 0;
		queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
		queueDesc.NodeMask = 0;

		ID3D12CommandQueue* commandQueue = nullptr;
		if (device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&commandQueue)) != S_OK)
		{
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			return Status::Error_GfxApiInitFailed;
		}

		ID3D12CommandAllocator* commandAllocator = nullptr;
		if (device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&commandAllocator)) < 0)
		{
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			return Status::Error_GfxApiInitFailed;
		}

		ID3D12GraphicsCommandList* commandList = nullptr;
		if (device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, commandAllocator, nullptr, IID_PPV_ARGS(&commandList)) < 0)
		{
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			return Status::Error_GfxApiInitFailed;
		}

		DXGI_RATIONAL refreshRate{};
		refreshRate.Numerator = 60;
		refreshRate.Denominator = 1;

		DXGI_MODE_DESC bufferDesc{};
		bufferDesc.Width = 100;
		bufferDesc.Height = 100;
		bufferDesc.RefreshRate = refreshRate;
		bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		DXGI_SAMPLE_DESC sampleDesc{};
		sampleDesc.Count = 1;
		sampleDesc.Quality = 0;

		DXGI_SWAP_CHAIN_DESC swapChainDesc{};
		swapChainDesc.BufferDesc = bufferDesc;
		swapChainDesc.SampleDesc = sampleDesc;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 2;
		swapChainDesc.OutputWindow = window;
		swapChainDesc.Windowed = 1;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

		IDXGISwapChain* swapChain = nullptr;
		if (factory->CreateSwapChain(commandQueue, &swapChainDesc, &swapChain) != S_OK)
		{
			::DestroyWindow(window);
			::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
			return Status::Error_GfxApiInitFailed;
		}

		bool deviceEntriesAdded = false;
#if defined(__ID3D12Device10_INTERFACE_DEFINED__)
		ID3D12Device10* device10 = nullptr;
		if (HRESULT hr = device->QueryInterface(IID_PPV_ARGS(&device10)); hr == S_OK && device10)
		{
			methodTable.AddEntries(device10, DEVICE10_ENTRIES, MAX_DEVICE_ENTRIES);
			SafeRelease(device10);
			deviceEntriesAdded = true;
		}
#endif
#if defined(__ID3D12Device9_INTERFACE_DEFINED__)
		ID3D12Device9* device9 = nullptr;
		if (HRESULT hr = device->QueryInterface(IID_PPV_ARGS(&device9)); !deviceEntriesAdded && hr == S_OK && device9)
		{
			methodTable.AddEntries(device9, DEVICE9_ENTRIES, MAX_DEVICE_ENTRIES);
			SafeRelease(device9);
			deviceEntriesAdded = true;
		}
#endif
		if (!deviceEntriesAdded)
		{
			ID3D12Device8* device8 = nullptr;
			ID3D12Device7* device7 = nullptr;
			ID3D12Device6* device6 = nullptr;
			ID3D12Device5* device5 = nullptr;
			ID3D12Device4* device4 = nullptr;
			ID3D12Device3* device3 = nullptr;
			ID3D12Device2* device2 = nullptr;
			ID3D12Device1* device1 = nullptr;
			if (HRESULT hr = device->QueryInterface(IID_PPV_ARGS(&device8)); hr == S_OK && device8)
			{
				methodTable.AddEntries(device8, DEVICE8_ENTRIES, MAX_DEVICE_ENTRIES);
				SafeRelease(device8);
			}
			else if (HRESULT hr = device->QueryInterface(IID_PPV_ARGS(&device7)); hr == S_OK && device7)
			{
				methodTable.AddEntries(device7, DEVICE7_ENTRIES, MAX_DEVICE_ENTRIES);
				SafeRelease(device7);
			}
			else if (HRESULT hr = device->QueryInterface(IID_PPV_ARGS(&device6)); hr == S_OK && device6)
			{
				methodTable.AddEntries(device6, DEVICE6_ENTRIES, MAX_DEVICE_ENTRIES);
				SafeRelease(device6);
			}
			else if (HRESULT hr = device->QueryInterface(IID_PPV_ARGS(&device5)); hr == S_OK && device5)
			{
				methodTable.AddEntries(device5, DEVICE5_ENTRIES, MAX_DEVICE_ENTRIES);
				SafeRelease(device5);
			}
			else if (HRESULT hr = device->QueryInterface(IID_PPV_ARGS(&device4)); hr == S_OK && device4)
			{
				methodTable.AddEntries(device4, DEVICE4_ENTRIES, MAX_DEVICE_ENTRIES);
				SafeRelease(device4);
			}
			else if (HRESULT hr = device->QueryInterface(IID_PPV_ARGS(&device3)); hr == S_OK && device3)
			{
				methodTable.AddEntries(device3, DEVICE3_ENTRIES, MAX_DEVICE_ENTRIES);
				SafeRelease(device3);
			}
			else if (HRESULT hr = device->QueryInterface(IID_PPV_ARGS(&device2)); hr == S_OK && device2)
			{
				methodTable.AddEntries(device2, DEVICE2_ENTRIES, MAX_DEVICE_ENTRIES);
				SafeRelease(device2);
			}
			else if (HRESULT hr = device->QueryInterface(IID_PPV_ARGS(&device1)); hr == S_OK && device1)
			{
				methodTable.AddEntries(device1, DEVICE1_ENTRIES, MAX_DEVICE_ENTRIES);
				SafeRelease(device1);
			}
			else
			{
				methodTable.AddEntries(device, DEVICE_ENTRIES);
			}
		}
		
		methodTable.AddEntries(commandQueue, QUEUE_ENTRIES);
		methodTable.AddEntries(commandAllocator, ALLOCATOR_ENTRIES);
		methodTable.AddEntries(commandList, LIST_ENTRIES);

        IDXGISwapChain3* swapChain3 = nullptr;
		IDXGISwapChain2* swapChain2 = nullptr;
		IDXGISwapChain1* swapChain1 = nullptr;
		if (HRESULT hr = swapChain->QueryInterface(IID_PPV_ARGS(&swapChain3)); hr == S_OK && swapChain3)
		{
			methodTable.AddEntries(swapChain3, SWAPCHAIN3_ENTRIES, MAX_SWAPCHAIN_ENTRIES);
			SafeRelease(swapChain3);
		}
		else if (HRESULT hr = swapChain->QueryInterface(IID_PPV_ARGS(&swapChain2)); hr == S_OK && swapChain2)
		{
			methodTable.AddEntries(swapChain2, SWAPCHAIN2_ENTRIES, MAX_SWAPCHAIN_ENTRIES);
			SafeRelease(swapChain2);
		}
		else if (HRESULT hr = swapChain->QueryInterface(IID_PPV_ARGS(&swapChain1)); hr == S_OK && swapChain1)
		{
			methodTable.AddEntries(swapChain1, SWAPCHAIN1_ENTRIES, MAX_SWAPCHAIN_ENTRIES);
			SafeRelease(swapChain1);
		}
		else
		{
			methodTable.AddEntries(swapChain, SWAPCHAIN_ENTRIES, MAX_SWAPCHAIN_ENTRIES);
		}

        SafeRelease(device);
        SafeRelease(commandQueue);
        SafeRelease(commandAllocator);
        SafeRelease(commandList);
        SafeRelease(swapChain);

		::DestroyWindow(window);
		::UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);

		return Status::Success;
	}

}

