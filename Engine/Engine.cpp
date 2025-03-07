#include "pch.h"
#include "Engine.h"


void Engine::Init(const WindowInfo& info)
{
	_window = info;

	// 그려질 화면 크기를 결정
	_viewport = { 0, 0, static_cast<FLOAT>(info.width), static_cast<FLOAT>(info.height), 0.0f, 1.0f };
	_scissorRect = CD3DX12_RECT(0, 0, info.width, info.height);

	_device = make_shared<Device>();
	_cmdQueue = make_shared<CommandQueue>();
	_swapChain = make_shared<SwapChain>();
	_rootSignature = make_shared<RootSignature>();
	_cb = make_shared<ConstantBuffer>();
	_tableDescHeap = make_shared<TableDescriptorHeap>();
	_depthStencilBuffer = make_shared<DepthStencilBuffer>();
	
	_device->Init();
	_cmdQueue->Init(_device->GetDevice(), _swapChain);
	_swapChain->Init(info, _device->GetDevice(), _device->GetDXGI(), _cmdQueue->GetCmdQueue());
	_rootSignature->Init();
	_cb->Init(sizeof(Transform), 256);
	_tableDescHeap->Init(256);
	_depthStencilBuffer->Init(_window);

	ResizeWindow(info.width, info.height);
}

void Engine::Render()
{
	RenderBegin();

	// TODO : // 나머지 물체를 그려준다
	RenderEnd();
}

void Engine::RenderBegin()
{
	_cmdQueue->RenderBegin(&_viewport, &_scissorRect);
}

void Engine::RenderEnd()
{
	_cmdQueue->RenderEnd();
}

void Engine::ResizeWindow(int32 width, int32 height)
{
	_window.width = width;
	_window.height = height;

	RECT rect = { 0, 0, width, height };
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); // 윈도우 크기 조절
	::SetWindowPos(_window.hwnd, 0, 100, 100, width, height, 0); // 윈도우 포지션을 내가 원하는 위치에

	_depthStencilBuffer->Init(_window);
}
