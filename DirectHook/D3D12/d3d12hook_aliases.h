#pragma once
#include <d3d12.h>
#include <dxgi1_4.h>

namespace directhook::d3d12
{
	using PFN_D3D12Device_QueryInterface = HRESULT(*)(ID3D12Device*, REFIID, void**);
	using PFN_D3D12Device_AddRef = ULONG(*)(ID3D12Device*);
	using PFN_D3D12Device_Release = ULONG(*)(ID3D12Device*);
	using PFN_D3D12Device_GetPrivateData = HRESULT(*)(ID3D12Device*, REFGUID, UINT*, void*);
	using PFN_D3D12Device_SetPrivateData = HRESULT(*)(ID3D12Device*, REFGUID, UINT, const void*);
	using PFN_D3D12Device_SetPrivateDataInterface = HRESULT(*)(ID3D12Device*, REFGUID, const IUnknown*);
	using PFN_D3D12Device_SetName = HRESULT(*)(ID3D12Device*, LPCWSTR);
	using PFN_D3D12Device_GetNodeCount = UINT(*)(ID3D12Device*);
	using PFN_D3D12Device_CreateCommandQueue = HRESULT(*)(ID3D12Device*, const D3D12_COMMAND_QUEUE_DESC*, REFIID, void**);
	using PFN_D3D12Device_CreateCommandAllocator = HRESULT(*)(ID3D12Device*, D3D12_COMMAND_LIST_TYPE, REFIID, void**);
	using PFN_D3D12Device_CreateGraphicsPipelineState = HRESULT(*)(ID3D12Device*, const D3D12_GRAPHICS_PIPELINE_STATE_DESC*, REFIID, void**);
	using PFN_D3D12Device_CreateComputePipelineState = HRESULT(*)(ID3D12Device*, const D3D12_COMPUTE_PIPELINE_STATE_DESC*, REFIID, void**);
	using PFN_D3D12Device_CreateCommandList = HRESULT(*)(ID3D12Device*, UINT, D3D12_COMMAND_LIST_TYPE, ID3D12CommandAllocator*, ID3D12PipelineState*, REFIID, void**);
	using PFN_D3D12Device_CheckFeatureSupport = HRESULT(*)(ID3D12Device*, D3D12_FEATURE, void*, UINT);
	using PFN_D3D12Device_CreateDescriptorHeap = HRESULT(*)(ID3D12Device*, const D3D12_DESCRIPTOR_HEAP_DESC*, REFIID, void**);
	using PFN_D3D12Device_GetDescriptorHandleIncrementSize = UINT(*)(ID3D12Device*, D3D12_DESCRIPTOR_HEAP_TYPE);
	using PFN_D3D12Device_CreateRootSignature = HRESULT(*)(ID3D12Device*, UINT, const void*, SIZE_T, REFIID, void**);
	using PFN_D3D12Device_CreateConstantBufferView = void(*)(ID3D12Device*, const D3D12_CONSTANT_BUFFER_VIEW_DESC*, D3D12_CPU_DESCRIPTOR_HANDLE);
	using PFN_D3D12Device_CreateShaderResourceView = void(*)(ID3D12Device*, ID3D12Resource*, const D3D12_SHADER_RESOURCE_VIEW_DESC*, D3D12_CPU_DESCRIPTOR_HANDLE);
	using PFN_D3D12Device_CreateUnorderedAccessView = void(*)(ID3D12Device*, ID3D12Resource*, ID3D12Resource*, const D3D12_UNORDERED_ACCESS_VIEW_DESC*, D3D12_CPU_DESCRIPTOR_HANDLE);
	using PFN_D3D12Device_CreateRenderTargetView = void(*)(ID3D12Device*, ID3D12Resource*, const D3D12_RENDER_TARGET_VIEW_DESC*, D3D12_CPU_DESCRIPTOR_HANDLE);
	using PFN_D3D12Device_CreateDepthStencilView = void(*)(ID3D12Device*, ID3D12Resource*, const D3D12_DEPTH_STENCIL_VIEW_DESC*, D3D12_CPU_DESCRIPTOR_HANDLE);
	using PFN_D3D12Device_CreateSampler = void(*)(ID3D12Device*, const D3D12_SAMPLER_DESC*, D3D12_CPU_DESCRIPTOR_HANDLE);
	using PFN_D3D12Device_CopyDescriptors = void(*)(ID3D12Device*, UINT, const D3D12_CPU_DESCRIPTOR_HANDLE*, UINT, const D3D12_CPU_DESCRIPTOR_HANDLE*, UINT, D3D12_DESCRIPTOR_HEAP_TYPE);
	using PFN_D3D12Device_CopyDescriptorsSimple = void(*)(ID3D12Device*, UINT, D3D12_CPU_DESCRIPTOR_HANDLE, D3D12_CPU_DESCRIPTOR_HANDLE, D3D12_DESCRIPTOR_HEAP_TYPE);
	using PFN_D3D12Device_GetResourceAllocationInfo = D3D12_RESOURCE_ALLOCATION_INFO(*)(ID3D12Device*, UINT, const D3D12_RESOURCE_DESC*);
	using PFN_D3D12Device_GetCustomHeapProperties = D3D12_HEAP_PROPERTIES(*)(ID3D12Device*, UINT, D3D12_HEAP_TYPE);
	using PFN_D3D12Device_CreateCommittedResource = HRESULT(*)(ID3D12Device*, const D3D12_HEAP_PROPERTIES*, D3D12_HEAP_FLAGS, const D3D12_RESOURCE_DESC*, D3D12_RESOURCE_STATES, const D3D12_CLEAR_VALUE*, REFIID, void**);
	using PFN_D3D12Device_CreateHeap = HRESULT(*)(ID3D12Device*, const D3D12_HEAP_DESC*, REFIID, void**);
	using PFN_D3D12Device_CreatePlacedResource = HRESULT(*)(ID3D12Device*, ID3D12Heap*, UINT64, const D3D12_RESOURCE_DESC*, D3D12_RESOURCE_STATES, const D3D12_CLEAR_VALUE*, REFIID, void**);
	using PFN_D3D12Device_CreateReservedResource = HRESULT(*)(ID3D12Device*, const D3D12_RESOURCE_DESC*, D3D12_RESOURCE_STATES, const D3D12_CLEAR_VALUE*, REFIID, void**);
	using PFN_D3D12Device_CreateSharedHandle = HRESULT(*)(ID3D12Device*, ID3D12Resource*, const SECURITY_ATTRIBUTES*, LPCWSTR, HANDLE*);
	using PFN_D3D12Device_OpenSharedHandle = HRESULT(*)(ID3D12Device*, HANDLE, REFIID, void**);
	using PFN_D3D12Device_OpenSharedHandleByName = HRESULT(*)(ID3D12Device*, LPCWSTR, DWORD, REFIID, void**);
	using PFN_D3D12Device_MakeResident = HRESULT(*)(ID3D12Device*, UINT, ID3D12Resource* const*);
	using PFN_D3D12Device_Evict = HRESULT(*)(ID3D12Device*, UINT, ID3D12Resource* const*);
	using PFN_D3D12Device_CreateFence = HRESULT(*)(ID3D12Device*, UINT64, D3D12_FENCE_FLAGS, REFIID, void**);
	using PFN_D3D12Device_GetDeviceRemovedReason = HRESULT(*)(ID3D12Device*);
	using PFN_D3D12Device_GetCopyableFootprints = void(*)(ID3D12Device*, const D3D12_RESOURCE_DESC*, UINT, UINT, D3D12_PLACED_SUBRESOURCE_FOOTPRINT*, UINT*, UINT64*);
	using PFN_D3D12Device_CreateQueryHeap = HRESULT(*)(ID3D12Device*, const D3D12_QUERY_HEAP_DESC*, REFIID, void**);
	using PFN_D3D12Device_SetStablePowerState = HRESULT(*)(ID3D12Device*, BOOL);
	using PFN_D3D12Device_CreateCommandSignature = HRESULT(*)(ID3D12Device*, const D3D12_COMMAND_SIGNATURE_DESC*, REFIID, void**);
	using PFN_D3D12Device_GetResourceTiling = void(*)(ID3D12Device*, ID3D12Resource*, UINT*, UINT*, D3D12_SUBRESOURCE_TILING*, UINT*);
	using PFN_D3D12Device_GetAdapterLuid = LUID(*)(ID3D12Device*);

	using PFN_ID3D12Device1_CreatePipelineLibrary = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device1*, const void*, SIZE_T, REFIID, void**);
	using PFN_ID3D12Device1_SetEventOnMultipleFenceCompletion = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device1*, UINT, const HANDLE*, D3D12_FENCE_FLAGS, HANDLE);
	using PFN_ID3D12Device1_SetResidencyPriority = void (STDMETHODCALLTYPE*)(ID3D12Device1*, UINT, ID3D12Resource* const*, D3D12_RESIDENCY_PRIORITY*);

	using PFN_ID3D12Device2_CreatePipelineState = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device2*, const D3D12_PIPELINE_STATE_STREAM_DESC*, REFIID, void**);

	using PFN_ID3D12Device3_OpenExistingHeapFromFileMapping = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device3*, HANDLE, REFIID, void**);
	using PFN_ID3D12Device3_OpenExistingHeapFromAddress = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device3*, void*, REFIID, void**);
	using PFN_ID3D12Device3_EnqueueMakeResident = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device3*, UINT, ID3D12Resource* const*, UINT*);

	using PFN_ID3D12Device4_CreateCommandList1 = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device4*, UINT, D3D12_COMMAND_LIST_TYPE, D3D12_COMMAND_LIST_FLAGS, REFIID, void**);
	using PFN_ID3D12Device4_CreateProtectedResourceSession = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device4*, const D3D12_PROTECTED_RESOURCE_SESSION_DESC*, REFIID, void**);
	using PFN_ID3D12Device4_CreateCommittedResource1 = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device4*, const D3D12_HEAP_PROPERTIES*, D3D12_HEAP_FLAGS, const D3D12_RESOURCE_DESC*, D3D12_RESOURCE_STATES, const D3D12_CLEAR_VALUE*, ID3D12ProtectedResourceSession*, REFIID, void**);
	using PFN_ID3D12Device4_CreateHeap1 = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device4*, const D3D12_HEAP_DESC*, ID3D12ProtectedResourceSession*, REFIID, void**);
	using PFN_ID3D12Device4_CreateReservedResource1 = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device4*, const D3D12_RESOURCE_DESC*, D3D12_RESOURCE_STATES, const D3D12_CLEAR_VALUE*, ID3D12ProtectedResourceSession*, REFIID, void**);
	using PFN_ID3D12Device4_GetResourceAllocationInfo1 = void (STDMETHODCALLTYPE*)(ID3D12Device4*, UINT, UINT, const D3D12_RESOURCE_DESC*, const D3D12_RESOURCE_ALLOCATION_INFO*);

	using PFN_ID3D12Device5_CreateLifetimeTracker = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device5*, ID3D12LifetimeOwner*, REFIID, void**);
	using PFN_ID3D12Device5_RemoveDevice = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device5*);
	using PFN_ID3D12Device5_EnumerateMetaCommands = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device5*, UINT*, D3D12_META_COMMAND_DESC*);
	using PFN_ID3D12Device5_EnumerateMetaCommandParameters = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device5*, REFGUID, D3D12_META_COMMAND_PARAMETER_STAGE, UINT*, UINT*, D3D12_META_COMMAND_PARAMETER_DESC*);
	using PFN_ID3D12Device5_CreateMetaCommand = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device5*, REFGUID, UINT, const void*, SIZE_T, REFIID, void**);
	using PFN_ID3D12Device5_CreateStateObject = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device5*, const D3D12_STATE_OBJECT_DESC*, REFIID, void**);
	using PFN_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo = void (STDMETHODCALLTYPE*)(ID3D12Device5*, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS*, D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO*);
	using PFN_ID3D12Device5_CheckDriverMatchingIdentifier = HRESULT(STDMETHODCALLTYPE*)(ID3D12Device5*, D3D12_SERIALIZED_DATA_TYPE, const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER*);

	using PFN_D3D12CommandQueue_QueryInterface = HRESULT(*)(ID3D12CommandQueue*, REFIID, void**);
	using PFN_D3D12CommandQueue_AddRef = ULONG(*)(ID3D12CommandQueue*);
	using PFN_D3D12CommandQueue_Release = ULONG(*)(ID3D12CommandQueue*);
	using PFN_D3D12CommandQueue_GetPrivateData = HRESULT(*)(ID3D12CommandQueue*, REFGUID, UINT*, void*);
	using PFN_D3D12CommandQueue_SetPrivateData = HRESULT(*)(ID3D12CommandQueue*, REFGUID, UINT, const void*);
	using PFN_D3D12CommandQueue_SetPrivateDataInterface = HRESULT(*)(ID3D12CommandQueue*, REFGUID, const IUnknown*);
	using PFN_D3D12CommandQueue_SetName = HRESULT(*)(ID3D12CommandQueue*, LPCWSTR);
	using PFN_D3D12CommandQueue_GetDevice = HRESULT(*)(ID3D12CommandQueue*, REFIID, void**);
	using PFN_D3D12CommandQueue_UpdateTileMappings = void(*)(ID3D12CommandQueue*, ID3D12Resource*, UINT, const D3D12_TILED_RESOURCE_COORDINATE*, UINT, const D3D12_TILE_REGION_SIZE*, ID3D12Heap*, UINT, const D3D12_TILE_MAPPING_FLAGS*);
	using PFN_D3D12CommandQueue_CopyTileMappings = void(*)(ID3D12CommandQueue*, ID3D12Resource*, const D3D12_TILED_RESOURCE_COORDINATE*, ID3D12Resource*, const D3D12_TILED_RESOURCE_COORDINATE*, const D3D12_TILE_REGION_SIZE*, D3D12_TILE_MAPPING_FLAGS);
	using PFN_D3D12CommandQueue_ExecuteCommandLists = void(*)(ID3D12CommandQueue*, UINT, ID3D12CommandList* const*);
	using PFN_D3D12CommandQueue_SetMarker = HRESULT(*)(ID3D12CommandQueue*, UINT, const void*);
	using PFN_D3D12CommandQueue_BeginEvent = HRESULT(*)(ID3D12CommandQueue*, UINT, const void*);
	using PFN_D3D12CommandQueue_EndEvent = HRESULT(*)(ID3D12CommandQueue*);
	using PFN_D3D12CommandQueue_Signal = HRESULT(*)(ID3D12CommandQueue*, ID3D12Fence*, UINT64);
	using PFN_D3D12CommandQueue_Wait = HRESULT(*)(ID3D12CommandQueue*, ID3D12Fence*, UINT64);
	using PFN_D3D12CommandQueue_GetTimestampFrequency = HRESULT(*)(ID3D12CommandQueue*, UINT64*);
	using PFN_D3D12CommandQueue_GetClockCalibration = HRESULT(*)(ID3D12CommandQueue*, UINT64*, UINT64*);
	using PFN_D3D12CommandQueue_GetDesc = D3D12_COMMAND_QUEUE_DESC(*)(ID3D12CommandQueue*);

	using PFN_D3D12CommandAllocator_QueryInterface = HRESULT(*)(ID3D12CommandAllocator*, REFIID, void**);
	using PFN_D3D12CommandAllocator_AddRef = ULONG(*)(ID3D12CommandAllocator*);
	using PFN_D3D12CommandAllocator_Release = ULONG(*)(ID3D12CommandAllocator*);
	using PFN_D3D12CommandAllocator_GetPrivateData = HRESULT(*)(ID3D12CommandAllocator*, REFGUID, UINT*, void*);
	using PFN_D3D12CommandAllocator_SetPrivateData = HRESULT(*)(ID3D12CommandAllocator*, REFGUID, UINT, const void*);
	using PFN_D3D12CommandAllocator_SetPrivateDataInterface = HRESULT(*)(ID3D12CommandAllocator*, REFGUID, const IUnknown*);
	using PFN_D3D12CommandAllocator_SetName = HRESULT(*)(ID3D12CommandAllocator*, LPCWSTR);
	using PFN_D3D12CommandAllocator_GetDevice = HRESULT(*)(ID3D12CommandAllocator*, REFIID, void**);
	using PFN_D3D12CommandAllocator_Reset = HRESULT(*)(ID3D12CommandAllocator*);

	using PFN_D3D12CommandList_QueryInterface = HRESULT(*)(ID3D12CommandList*, REFIID, void**);
	using PFN_D3D12CommandList_AddRef = ULONG(*)(ID3D12CommandList*);
	using PFN_D3D12CommandList_Release = ULONG(*)(ID3D12CommandList*);
	using PFN_D3D12CommandList_GetPrivateData = HRESULT(*)(ID3D12CommandList*, REFGUID, UINT*, void*);
	using PFN_D3D12CommandList_SetPrivateData = HRESULT(*)(ID3D12CommandList*, REFGUID, UINT, const void*);
	using PFN_D3D12CommandList_SetPrivateDataInterface = HRESULT(*)(ID3D12CommandList*, REFGUID, const IUnknown*);
	using PFN_D3D12CommandList_SetName = HRESULT(*)(ID3D12CommandList*, LPCWSTR);
	using PFN_D3D12CommandList_GetDevice = HRESULT(*)(ID3D12CommandList*, REFIID, void**);
	using PFN_D3D12CommandList_GetType = D3D12_COMMAND_LIST_TYPE(*)(ID3D12CommandList*);
	using PFN_D3D12CommandList_Close = HRESULT(*)(ID3D12CommandList*);
	using PFN_D3D12CommandList_Reset = HRESULT(*)(ID3D12CommandList*, ID3D12CommandAllocator*, ID3D12PipelineState*);
	using PFN_D3D12CommandList_ClearState = void(*)(ID3D12CommandList*);
	using PFN_D3D12CommandList_DrawInstanced = void(*)(ID3D12CommandList*, UINT, UINT, UINT, UINT);
	using PFN_D3D12CommandList_DrawIndexedInstanced = void(*)(ID3D12CommandList*, UINT, UINT, UINT, INT, UINT);
	using PFN_D3D12CommandList_Dispatch = void(*)(ID3D12CommandList*, UINT, UINT, UINT);
	using PFN_D3D12CommandList_CopyBufferRegion = void(*)(ID3D12CommandList*, ID3D12Resource*, UINT, ID3D12Resource*, UINT, UINT);
	using PFN_D3D12CommandList_CopyTextureRegion = void(*)(ID3D12CommandList*, const D3D12_TEXTURE_COPY_LOCATION*, UINT, UINT, UINT, const D3D12_TEXTURE_COPY_LOCATION*, const D3D12_BOX*);
	using PFN_D3D12CommandList_CopyResource = void(*)(ID3D12CommandList*, ID3D12Resource*, ID3D12Resource*);
	using PFN_D3D12CommandList_CopyTiles = void(*)(ID3D12CommandList*, ID3D12Resource*, UINT, const D3D12_TILED_RESOURCE_COORDINATE*, const D3D12_TILE_REGION_SIZE*, ID3D12Resource*, UINT, D3D12_TILE_COPY_FLAGS);
	using PFN_D3D12CommandList_ResolveSubresource = void(*)(ID3D12CommandList*, ID3D12Resource*, UINT, ID3D12Resource*, UINT, DXGI_FORMAT);
	using PFN_D3D12CommandList_IASetPrimitiveTopology = void(*)(ID3D12CommandList*, D3D12_PRIMITIVE_TOPOLOGY);
	using PFN_D3D12CommandList_RSSetViewports = void(*)(ID3D12CommandList*, UINT, const D3D12_VIEWPORT*);
	using PFN_D3D12CommandList_RSSetScissorRects = void(*)(ID3D12CommandList*, UINT, const D3D12_RECT*);
	using PFN_D3D12CommandList_OMSetBlendFactor = void(*)(ID3D12CommandList*, const FLOAT*);
	using PFN_D3D12CommandList_OMSetStencilRef = void(*)(ID3D12CommandList*, UINT);
	using PFN_D3D12CommandList_SetPipelineState = void(*)(ID3D12CommandList*, ID3D12PipelineState*);
	using PFN_D3D12CommandList_ResourceBarrier = void(*)(ID3D12CommandList*, UINT, const D3D12_RESOURCE_BARRIER*);
	using PFN_D3D12CommandList_ExecuteBundle = void(*)(ID3D12CommandList*, ID3D12CommandList*);
	using PFN_D3D12CommandList_SetDescriptorHeaps = void(*)(ID3D12CommandList*, UINT, ID3D12DescriptorHeap**);
	using PFN_D3D12CommandList_SetComputeRootSignature = void(*)(ID3D12CommandList*, ID3D12RootSignature*);
	using PFN_D3D12CommandList_SetGraphicsRootSignature = void(*)(ID3D12CommandList*, ID3D12RootSignature*);
	using PFN_D3D12CommandList_SetComputeRootDescriptorTable = void(*)(ID3D12CommandList*, UINT, D3D12_GPU_DESCRIPTOR_HANDLE);
	using PFN_D3D12CommandList_SetGraphicsRootDescriptorTable = void(*)(ID3D12CommandList*, UINT, D3D12_GPU_DESCRIPTOR_HANDLE);
	using PFN_D3D12CommandList_SetComputeRoot32BitConstant = void(*)(ID3D12CommandList*, UINT, UINT, UINT);
	using PFN_D3D12CommandList_SetGraphicsRoot32BitConstant = void(*)(ID3D12CommandList*, UINT, UINT, UINT);
	using PFN_D3D12CommandList_SetComputeRoot32BitConstants = void(*)(ID3D12CommandList*, UINT, UINT, const void*, UINT);
	using PFN_D3D12CommandList_SetGraphicsRoot32BitConstants = void(*)(ID3D12CommandList*, UINT, UINT, const void*, UINT);
	using PFN_D3D12CommandList_SetComputeRootConstantBufferView = void(*)(ID3D12CommandList*, UINT, D3D12_GPU_VIRTUAL_ADDRESS);
	using PFN_D3D12CommandList_SetGraphicsRootConstantBufferView = void(*)(ID3D12CommandList*, UINT, D3D12_GPU_VIRTUAL_ADDRESS);
	using PFN_D3D12CommandList_SetComputeRootShaderResourceView = void(*)(ID3D12CommandList*, UINT, D3D12_GPU_VIRTUAL_ADDRESS);
	using PFN_D3D12CommandList_SetGraphicsRootShaderResourceView = void(*)(ID3D12CommandList*, UINT, D3D12_GPU_VIRTUAL_ADDRESS);
	using PFN_D3D12CommandList_SetComputeRootUnorderedAccessView = void(*)(ID3D12CommandList*, UINT, D3D12_GPU_VIRTUAL_ADDRESS);
	using PFN_D3D12CommandList_SetGraphicsRootUnorderedAccessView = void(*)(ID3D12CommandList*, UINT, D3D12_GPU_VIRTUAL_ADDRESS);
	using PFN_D3D12CommandList_IASetIndexBuffer = void(*)(ID3D12CommandList*, const D3D12_INDEX_BUFFER_VIEW*);
	using PFN_D3D12CommandList_IASetVertexBuffers = void(*)(ID3D12CommandList*, UINT, UINT, const D3D12_VERTEX_BUFFER_VIEW*);
	using PFN_D3D12CommandList_SOSetTargets = void(*)(ID3D12CommandList*, UINT, UINT, const D3D12_STREAM_OUTPUT_BUFFER_VIEW*);
	using PFN_D3D12CommandList_OMSetRenderTargets = void(*)(ID3D12CommandList*, UINT, const D3D12_CPU_DESCRIPTOR_HANDLE*, BOOL, const D3D12_CPU_DESCRIPTOR_HANDLE*);
	using PFN_D3D12CommandList_ClearDepthStencilView = void(*)(ID3D12CommandList*, D3D12_CPU_DESCRIPTOR_HANDLE, UINT, FLOAT, UINT, UINT, const UINT*, UINT, const D3D12_RECT*);
	using PFN_D3D12CommandList_ClearRenderTargetView = void(*)(ID3D12CommandList*, D3D12_CPU_DESCRIPTOR_HANDLE, const FLOAT*, UINT, const D3D12_RECT*);
	using PFN_D3D12CommandList_ClearUnorderedAccessViewUint = void(*)(ID3D12CommandList*, D3D12_CPU_DESCRIPTOR_HANDLE, ID3D12Resource*, const UINT*, UINT, const D3D12_RECT*);
	using PFN_D3D12CommandList_ClearUnorderedAccessViewFloat = void(*)(ID3D12CommandList*, D3D12_CPU_DESCRIPTOR_HANDLE, ID3D12Resource*, const FLOAT*, UINT, const D3D12_RECT*);
	using PFN_D3D12CommandList_DiscardResource = void(*)(ID3D12CommandList*, ID3D12Resource*, const D3D12_DISCARD_REGION*);
	using PFN_D3D12CommandList_BeginQuery = void(*)(ID3D12CommandList*, ID3D12QueryHeap*, D3D12_QUERY_TYPE, UINT);
	using PFN_D3D12CommandList_EndQuery = void(*)(ID3D12CommandList*, ID3D12QueryHeap*, D3D12_QUERY_TYPE, UINT);
	using PFN_D3D12CommandList_ResolveQueryData = void(*)(ID3D12CommandList*, ID3D12QueryHeap*, D3D12_QUERY_TYPE, UINT, UINT, ID3D12Resource*, UINT, UINT);
	using PFN_D3D12CommandList_SetPredication = void(*)(ID3D12CommandList*, ID3D12Resource*, UINT, D3D12_PREDICATION_OP);
	using PFN_D3D12CommandList_SetMarker = void(*)(ID3D12CommandList*, UINT, const void*);
	using PFN_D3D12CommandList_BeginEvent = void(*)(ID3D12CommandList*, UINT, const void*);
	using PFN_D3D12CommandList_EndEvent = void(*)(ID3D12CommandList*);
	using PFN_D3D12CommandList_ExecuteIndirect = void(*)(ID3D12CommandList*, ID3D12CommandSignature*, UINT, ID3D12Resource*, UINT, ID3D12Resource*, UINT, void*);

	using PFN_IDXGISwapChain_QueryInterface = HRESULT(*)(IDXGISwapChain*, REFIID, void**);
	using PFN_IDXGISwapChain_AddRef = ULONG(*)(IDXGISwapChain*);
	using PFN_IDXGISwapChain_Release = ULONG(*)(IDXGISwapChain*);
	using PFN_IDXGISwapChain_SetPrivateData = HRESULT(*)(IDXGISwapChain*, REFGUID, UINT, const void*);
	using PFN_IDXGISwapChain_SetPrivateDataInterface = HRESULT(*)(IDXGISwapChain*, REFGUID, const IUnknown*);
	using PFN_IDXGISwapChain_GetPrivateData = HRESULT(*)(IDXGISwapChain*, REFGUID, UINT*, void*);
	using PFN_IDXGISwapChain_GetParent = HRESULT(*)(IDXGISwapChain*, REFIID, void**);
	using PFN_IDXGISwapChain_GetDevice = HRESULT(*)(IDXGISwapChain*, REFIID, void**);
	using PFN_IDXGISwapChain_Present = HRESULT(*)(IDXGISwapChain*, UINT, UINT);
	using PFN_IDXGISwapChain_GetBuffer = HRESULT(*)(IDXGISwapChain*, UINT, REFIID, void**);
	using PFN_IDXGISwapChain_SetFullscreenState = HRESULT(*)(IDXGISwapChain*, BOOL, IDXGIOutput*);
	using PFN_IDXGISwapChain_GetFullscreenState = HRESULT(*)(IDXGISwapChain*, BOOL*, IDXGIOutput**);
	using PFN_IDXGISwapChain_GetDesc = HRESULT(*)(IDXGISwapChain*, DXGI_SWAP_CHAIN_DESC*);
	using PFN_IDXGISwapChain_ResizeBuffers = HRESULT(*)(IDXGISwapChain*, UINT, UINT, DXGI_FORMAT, UINT);
	using PFN_IDXGISwapChain_ResizeTarget = HRESULT(*)(IDXGISwapChain*, const DXGI_MODE_DESC*);
	using PFN_IDXGISwapChain_GetContainingOutput = HRESULT(*)(IDXGISwapChain*, IDXGIOutput**);
	using PFN_IDXGISwapChain_GetFrameStatistics = HRESULT(*)(IDXGISwapChain*, DXGI_FRAME_STATISTICS*);
	using PFN_IDXGISwapChain_GetLastPresentCount = HRESULT(*)(IDXGISwapChain*, UINT*);

    using PFN_DXGISwapChain1_GetBackgroundColor = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain1*, DXGI_RGBA*);
    using PFN_DXGISwapChain1_GetCoreWindow = HWND(STDMETHODCALLTYPE*)(IDXGISwapChain1*);
    using PFN_DXGISwapChain1_GetDesc1 = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain1*, DXGI_SWAP_CHAIN_DESC1*);
    using PFN_DXGISwapChain1_GetFullscreenDesc = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain1*, DXGI_SWAP_CHAIN_FULLSCREEN_DESC*);
    using PFN_DXGISwapChain1_GetHwnd = HWND(STDMETHODCALLTYPE*)(IDXGISwapChain1*);
    using PFN_DXGISwapChain1_GetRestrictToOutput = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain1*, IDXGIOutput**);
    using PFN_DXGISwapChain1_GetRotation = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain1*, DXGI_MODE_ROTATION*);
    using PFN_DXGISwapChain1_IsTemporaryMonoSupported = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain1*, BOOL*);
    using PFN_DXGISwapChain1_Present1 = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain1*, UINT, const DXGI_PRESENT_PARAMETERS*);
    using PFN_DXGISwapChain1_SetBackgroundColor = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain1*, const DXGI_RGBA*);
    using PFN_DXGISwapChain1_SetRotation = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain1*, DXGI_MODE_ROTATION*);

    using PFN_DXGISwapChain2_GetFrameLatencyWaitableObject = HANDLE(STDMETHODCALLTYPE*)(IDXGISwapChain2*);
    using PFN_DXGISwapChain2_GetMatrixTransform = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain2*, DXGI_MATRIX_3X2_F*);
    using PFN_DXGISwapChain2_GetMaximumFrameLatency = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain2*, UINT*);
    using PFN_DXGISwapChain2_GetSourceSize = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain2*, UINT*, UINT*);
    using PFN_DXGISwapChain2_SetMatrixTransform = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain2*, const DXGI_MATRIX_3X2_F*);
    using PFN_DXGISwapChain2_SetMaximumFrameLatency = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain2*, UINT);
    using PFN_DXGISwapChain2_SetSourceSize = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain2*, UINT, UINT);

    using PFN_DXGISwapChain3_CheckColorSpaceSupport = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain3*, DXGI_COLOR_SPACE_TYPE, UINT*);
    using PFN_DXGISwapChain3_GetCurrentBackBufferIndex = UINT(STDMETHODCALLTYPE*)(IDXGISwapChain3*);
    using PFN_DXGISwapChain3_ResizeBuffers1 = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain3*, UINT, UINT, UINT, DXGI_FORMAT, UINT, const UINT*, IUnknown* const*);
    using PFN_DXGISwapChain3_SetColorSpace1 = HRESULT(STDMETHODCALLTYPE*)(IDXGISwapChain3*, DXGI_COLOR_SPACE_TYPE);
}