#include "DrnPCH.h"
#include "Renderer.h"

namespace Drn
{
	ID3D12Device* Renderer::g_Device;

	void Renderer::Init()
	{
		std::cout << "Renderer start!" << std::endl;

//#if DRN_DEBUG
		// Default to true for debug builds
		Microsoft::WRL::ComPtr<ID3D12Debug> debugInterface;
		if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugInterface))))
		{
			debugInterface->EnableDebugLayer();
		}
		else
		{
			// TODO: error
			//("WARNING:  Unable to enable D3D12 debug validation layer\n");
		}
//#endif

		DWORD dxgiFactoryFlags = 0;

#if DRN_DEBUG
		Microsoft::WRL::ComPtr<IDXGIInfoQueue> dxgiInfoQueue;
		if (SUCCEEDED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(dxgiInfoQueue.GetAddressOf()))))
		{
			dxgiFactoryFlags = DXGI_CREATE_FACTORY_DEBUG;

			dxgiInfoQueue->SetBreakOnSeverity(DXGI_DEBUG_ALL, DXGI_INFO_QUEUE_MESSAGE_SEVERITY_ERROR, true);
			dxgiInfoQueue->SetBreakOnSeverity(DXGI_DEBUG_ALL, DXGI_INFO_QUEUE_MESSAGE_SEVERITY_CORRUPTION, true);;
		}
#endif
		
		Microsoft::WRL::ComPtr<IDXGIFactory6> dxgiFactory;
		// @todo:error
		CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&dxgiFactory));
		
		Microsoft::WRL::ComPtr<IDXGIAdapter1> pAdapter;


		SIZE_T MaxDedicatedVideoMemory = 0;
		UINT Index = 0;
		for (UINT i = 0; dxgiFactory->EnumAdapters1(i, &pAdapter) != DXGI_ERROR_NOT_FOUND; ++i)
		{
			DXGI_ADAPTER_DESC AdaptorDesc;
			pAdapter->GetDesc(&AdaptorDesc);

			if (AdaptorDesc.DedicatedVideoMemory > MaxDedicatedVideoMemory)
			{
				MaxDedicatedVideoMemory = AdaptorDesc.DedicatedVideoMemory;
				Index = i;
			}
		}

		dxgiFactory->EnumAdapters1(Index, &pAdapter);
		D3D12CreateDevice(pAdapter.Get(), D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&g_Device));
	}

	void Renderer::Shutdown()
	{
		std::cout << "Renderer shutdown!" << std::endl;

#if DRN_DEBUG
		ID3D12DebugDevice* debugInterface;
		if (SUCCEEDED(g_Device->QueryInterface(&debugInterface)))
		{
			debugInterface->ReportLiveDeviceObjects(D3D12_RLDO_DETAIL | D3D12_RLDO_IGNORE_INTERNAL);
			debugInterface->Release();
		}
#endif

		g_Device->Release();
		g_Device = nullptr;
	}

	void Renderer::Tick(float DeltaTime)
	{

	}

	

}