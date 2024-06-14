#pragma once
class Game
{
public:
	Game();
	~Game();
public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	void RenderBegin();
	void RenderEnd();
private:
	void CreateDeviceAndSwapChain();
	void CreateRenderTargetView();
	// ���� �ĸ� ���۸� �����ϴ� ����
	// View : � �ڿ����� ���ؼ� �±׸� �޾ư����� 
	// ���߿� GPU�� ģ���ϰ� �����ϱ� ���� �ο� ������ ��

	void SetViewport();

private:
	HWND _hwnd;
	uint32 _width = 0;
	uint32 _height = 0;

private:
	// Device & SwapChain
	ComPtr<ID3D11Device> _device; // ����Ʈ������
	ComPtr<ID3D11DeviceContext> _deviceContext;
	ComPtr<IDXGISwapChain> _swapChain;
	
	// RTV
	ComPtr<ID3D11RenderTargetView> _renderTargetView;
	D3D11_VIEWPORT _viewport = { 0 }; // ȭ���� �����ϴ� ����ü

	float _clearColor[4] = { 0.5f, 0.5f, 1.5f, 0.5f };
};

 