#pragma once

#define ENTRY_COUNT(Class)		(Class##_LastEntry - Class##_FirstEntry + 1)
#define ENTRY_COUNT_(Class, x)	(Class##x##_LastEntry - Class##_FirstEntry + 1)


namespace directhook::d3d11
{
	enum 
	{
		SwapChain_FirstEntry = 0,
		SwapChain_QueryInterface = SwapChain_FirstEntry,
		SwapChain_AddRef,
		SwapChain_Release,
		SwapChain_SetPrivateData,
		SwapChain_SetPrivateDataInterface,
		SwapChain_GetPrivateData,
		SwapChain_GetParent,
		SwapChain_GetDevice,
		SwapChain_Present,
		SwapChain_GetBuffer,
		SwapChain_SetFullscreenState,
		SwapChain_GetFullscreenState,
		SwapChain_GetDesc,
		SwapChain_ResizeBuffers,
		SwapChain_ResizeTarget,
		SwapChain_GetContainingOutput,
		SwapChain_GetFrameStatistics,
		SwapChain_GetLastPresentCount,
		SwapChain_LastEntry = SwapChain_GetLastPresentCount,

		SwapChain1_GetBackgroundColor,
		SwapChain1_GetCoreWindow,
		SwapChain1_GetDesc1,
		SwapChain1_GetFullscreenDesc,
		SwapChain1_GetHwnd,
		SwapChain1_GetRestrictToOutput,
		SwapChain1_GetRotation,
		SwapChain1_IsTemporaryMonoSupported,
		SwapChain1_Present1,
		SwapChain1_SetBackgroundColor,
		SwapChain1_SetRotation,
        SwapChain1_LastEntry = SwapChain1_SetRotation,

		SwapChain2_GetFrameLatencyWaitableObject,
		SwapChain2_GetMatrixTransform,
		SwapChain2_GetMaximumFrameLatency,
		SwapChain2_GetSourceSize,
		SwapChain2_SetMatrixTransform,
		SwapChain2_SetMaximumFrameLatency,
		SwapChain2_SetSourceSize,
        SwapChain2_LastEntry = SwapChain2_SetSourceSize,

		SwapChain3_CheckColorSpaceSupport,
		SwapChain3_GetCurrentBackBufferIndex,
		SwapChain3_ResizeBuffers1,
		SwapChain3_SetColorSpace1,
        SwapChain3_LastEntry = SwapChain3_SetColorSpace1,

		Device_FirstEntry,
		Device_QueryInterface = Device_FirstEntry,
		Device_AddRef,
		Device_Release,
		Device_CreateBuffer,
		Device_CreateTexture1D,
		Device_CreateTexture2D,
		Device_CreateTexture3D,
		Device_CreateShaderResourceView,
		Device_CreateUnorderedAccessView,
		Device_CreateRenderTargetView,
		Device_CreateDepthStencilView,
		Device_CreateInputLayout,
		Device_CreateVertexShader,
		Device_CreateGeometryShader,
		Device_CreateGeometryShaderWithStreamOutput,
		Device_CreatePixelShader,
		Device_CreateHullShader,
		Device_CreateDomainShader,
		Device_CreateComputeShader,
		Device_CreateClassLinkage,
		Device_CreateBlendState,
		Device_CreateDepthStencilState,
		Device_CreateRasterizerState,
		Device_CreateSamplerState,
		Device_CreateQuery,
		Device_CreatePredicate,
		Device_CreateCounter,
		Device_CreateDeferredContext,
		Device_OpenSharedResource,
		Device_CheckFormatSupport,
		Device_CheckMultisampleQualityLevels,
		Device_CheckCounterInfo,
		Device_CheckCounter,
		Device_CheckFeatureSupport,
		Device_GetPrivateData,
		Device_SetPrivateData,
		Device_SetPrivateDataInterface,
		Device_GetFeatureLevel,
		Device_GetCreationFlags,
		Device_GetDeviceRemovedReason,
		Device_GetImmediateContext,
		Device_SetExceptionMode,
		Device_GetExceptionMode,
		Device_LastEntry = Device_GetExceptionMode,

		Device1_CreateBlendState1,
		Device1_CreateDeferredContext1,
		Device1_CreateDeviceContextState,
		Device1_CreateRasterizerState1,
		Device1_GetImmediateContext1,
		Device1_OpenSharedResource1,
		Device1_OpenSharedResourceByName,
		Device1_LastEntry = Device1_OpenSharedResourceByName,

		Device2_CheckMultisampleQualityLevels1,
		Device2_CreateDeferredContext2,
		Device2_GetImmediateContext2,
		Device2_GetResourceTiling,
		Device2_LastEntry = Device2_GetResourceTiling,

		Device3_CreateDeferredContext3,
		Device3_CreateQuery1,
		Device3_CreateRasterizerState2,
		Device3_CreateRenderTargetView1,
		Device3_CreateShaderResourceView1,
		Device3_CreateTexture2D1,
		Device3_CreateTexture3D1,
		Device3_CreateUnorderedAccessView1,
		Device3_GetImmediateContext3,
		Device3_ReadFromSubresource,
		Device3_WriteToSubresource,
		Device3_LastEntry = Device3_WriteToSubresource,

		Device4_RegisterDeviceRemovedEvent,
		Device4_UnregisterDeviceRemoved,
		Device4_LastEntry = Device4_UnregisterDeviceRemoved,

		Device5_CreateFence,
		Device5_OpenSharedFence,
		Device5_LastEntry = Device5_OpenSharedFence,

		Context_FirstEntry,
		Context_QueryInterface = Context_FirstEntry,
		Context_AddRef,
		Context_Release,
		Context_GetDevice,
		Context_GetPrivateData,
		Context_SetPrivateData,
		Context_SetPrivateDataInterface,
		Context_VSSetConstantBuffers,
		Context_PSSetShaderResources,
		Context_PSSetShader,
		Context_PSSetSamplers,
		Context_VSSetShader,
		Context_DrawIndexed,
		Context_Draw,
		Context_Map,
		Context_Unmap,
		Context_PSSetConstantBuffers,
		Context_IASetInputLayout,
		Context_IASetVertexBuffers,
		Context_IASetIndexBuffer,
		Context_DrawIndexedInstanced,
		Context_DrawInstanced,
		Context_GSSetConstantBuffers,
		Context_GSSetShader,
		Context_IASetPrimitiveTopology,
		Context_VSSetShaderResources,
		Context_VSSetSamplers,
		Context_Begin,
		Context_End,
		Context_GetData,
		Context_SetPredication,
		Context_GSSetShaderResources,
		Context_GSSetSamplers,
		Context_OMSetRenderTargets,
		Context_OMSetRenderTargetsAndUnorderedAccessViews,
		Context_OMSetBlendState,
		Context_OMSetDepthStencilState,
		Context_SOSetTargets,
		Context_DrawAuto,
		Context_DrawIndexedInstancedIndirect,
		Context_DrawInstancedIndirect,
		Context_Dispatch,
		Context_DispatchIndirect,
		Context_RSSetState,
		Context_RSSetViewports,
		Context_RSSetScissorRects,
		Context_CopySubresourceRegion,
		Context_CopyResource,
		Context_UpdateSubresource,
		Context_CopyStructureCount,
		Context_ClearRenderTargetView,
		Context_ClearUnorderedAccessViewUint,
		Context_ClearUnorderedAccessViewFloat,
		Context_ClearDepthStencilView,
		Context_GenerateMips,
		Context_SetResourceMinLOD,
		Context_GetResourceMinLOD,
		Context_ResolveSubresource,
		Context_ExecuteCommandList,
		Context_HSSetShaderResources,
		Context_HSSetShader,
		Context_HSSetSamplers,
		Context_HSSetConstantBuffers,
		Context_DSSetShaderResources,
		Context_DSSetShader,
		Context_DSSetSamplers,
		Context_DSSetConstantBuffers,
		Context_CSSetShaderResources,
		Context_CSSetUnorderedAccessViews,
		Context_CSSetShader,
		Context_CSSetSamplers,
		Context_CSSetConstantBuffers,
		Context_VSGetConstantBuffers,
		Context_PSGetShaderResources,
		Context_PSGetShader,
		Context_PSGetSamplers,
		Context_VSGetShader,
		Context_PSGetConstantBuffers,
		Context_IAGetInputLayout,
		Context_IAGetVertexBuffers,
		Context_IAGetIndexBuffer,
		Context_GSGetConstantBuffers,
		Context_GSGetShader,
		Context_IAGetPrimitiveTopology,
		Context_VSGetShaderResources,
		Context_VSGetSamplers,
		Context_GetPredication,
		Context_GSGetShaderResources,
		Context_GSGetSamplers,
		Context_OMGetRenderTargets,
		Context_OMGetRenderTargetsAndUnorderedAccessViews,
		Context_OMGetBlendState,
		Context_OMGetDepthStencilState,
		Context_SOGetTargets,
		Context_RSGetState,
		Context_RSGetViewports,
		Context_RSGetScissorRects,
		Context_HSGetShaderResources,
		Context_HSGetShader,
		Context_HSGetSamplers,
		Context_HSGetConstantBuffers,
		Context_DSGetShaderResources,
		Context_DSGetShader,
		Context_DSGetSamplers,
		Context_DSGetConstantBuffers,
		Context_CSGetShaderResources,
		Context_CSGetUnorderedAccessViews,
		Context_CSGetShader,
		Context_CSGetSamplers,
		Context_CSGetConstantBuffers,
		Context_ClearState,
		Context_Flush,
		Context_GetType,
		Context_GetContextFlags,
		Context_FinishCommandList,
		Context_CopySubresourceRegion1,
		Context_UpdateSubresource1,
		Context_DiscardResource,
		Context_DiscardView,
		Context_VSSetConstantBuffers1,
		Context_HSSetConstantBuffers1,
		Context_DSSetConstantBuffers1,
		Context_GSSetConstantBuffers1,
		Context_PSSetConstantBuffers1,
		Context_CSSetConstantBuffers1,
		Context_VSGetConstantBuffers1,
		Context_HSGetConstantBuffers1,
		Context_DSGetConstantBuffers1,
		Context_GSGetConstantBuffers1,
		Context_PSGetConstantBuffers1,
		Context_CSGetConstantBuffers1,
		Context_SwapDeviceContextState,
		Context_ClearView,
		Context_DiscardView1,
		Context_UpdateTileMappings,
		Context_CopyTileMappings,
		Context_CopyTiles,
		Context_UpdateTiles,
		Context_ResizeTilePool,
		Context_TiledResourceBarrier,
		Context_IsAnnotationEnabled,
		Context_SetMarkerInt,
		Context_BeginEventInt,
		Context_EndEvent,
		Context_LastEntry = Context_EndEvent,

		Context1_CopySubresourceRegion1,
		Context1_UpdateSubresource1,
		Context1_DiscardResource,
		Context1_DiscardView,
		Context1_VSSetConstantBuffers1,
		Context1_HSSetConstantBuffers1,
		Context1_DSSetConstantBuffers1,
		Context1_GSSetConstantBuffers1,
		Context1_PSSetConstantBuffers1,
		Context1_CSSetConstantBuffers1,
		Context1_VSGetConstantBuffers1,
		Context1_HSGetConstantBuffers1,
		Context1_DSGetConstantBuffers1,
		Context1_GSGetConstantBuffers1,
		Context1_PSGetConstantBuffers1,
		Context1_CSGetConstantBuffers1,
		Context1_SwapDeviceContextState,
		Context1_ClearView,
		Context1_DiscardView1,
		Context1_LastEntry = Context1_DiscardView1,

		Context2_UpdateTileMappings,
		Context2_CopyTileMappings,
		Context2_CopyTiles,
		Context2_UpdateTiles,
		Context2_ResizeTilePool,
		Context2_TiledResourceBarrier,
		Context2_IsAnnotationEnabled,
		Context2_SetMarkerInt,
		Context2_BeginEventInt,
		Context2_EndEvent,
		Context2_LastEntry = Context2_EndEvent,

		Context3_Flush1,
		Context3_GetHardwareProtectionState,
		Context3_SetHardwareProtectionState,
		Context3_LastEntry = Context3_SetHardwareProtectionState,

		Context4_Signal,
		Context4_Wait,
		Context4_LastEntry = Context4_Wait
	};

	static constexpr int SWAPCHAIN_ENTRIES = ENTRY_COUNT(SwapChain);
	static constexpr int SWAPCHAIN1_ENTRIES = ENTRY_COUNT_(SwapChain, 1);
	static constexpr int SWAPCHAIN2_ENTRIES = ENTRY_COUNT_(SwapChain, 2);
	static constexpr int SWAPCHAIN3_ENTRIES = ENTRY_COUNT_(SwapChain, 3);
	static constexpr int MAX_SWAPCHAIN_ENTRIES = SWAPCHAIN3_ENTRIES;

	static constexpr int DEVICE_ENTRIES = ENTRY_COUNT(Device);
	static constexpr int DEVICE1_ENTRIES = ENTRY_COUNT_(Device, 1);
	static constexpr int DEVICE2_ENTRIES = ENTRY_COUNT_(Device, 2);
	static constexpr int DEVICE3_ENTRIES = ENTRY_COUNT_(Device, 3);
	static constexpr int DEVICE4_ENTRIES = ENTRY_COUNT_(Device, 4);
	static constexpr int DEVICE5_ENTRIES = ENTRY_COUNT_(Device, 5);
	static constexpr int MAX_DEVICE_ENTRIES = DEVICE5_ENTRIES;

	static constexpr int CONTEXT_ENTRIES = ENTRY_COUNT(Context);
	static constexpr int CONTEXT1_ENTRIES = ENTRY_COUNT_(Context, 1);
	static constexpr int CONTEXT2_ENTRIES = ENTRY_COUNT_(Context, 2);
	static constexpr int CONTEXT3_ENTRIES = ENTRY_COUNT_(Context, 3);
	static constexpr int CONTEXT4_ENTRIES = ENTRY_COUNT_(Context, 4);
	static constexpr int MAX_CONTEXT_ENTRIES = CONTEXT4_ENTRIES;

}