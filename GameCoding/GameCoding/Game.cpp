#include "pch.h"
#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_width = GWinSizeX;
	_height = GWinSizeY;

	// TODO

	_device->AddRef();

	_device->Release();
}

void Game::Update()
{
}

void Game::Render()
{
}

void Game::CreateDeviceAndSwapChain()
{
	DXGI_SWAP_CHAIN_DESC desc;
	ZeroMemory(&desc, sizeof(desc)); // memset

	::D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,

	)
}
