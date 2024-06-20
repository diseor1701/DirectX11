#pragma once
class Graphics
{
public:
	Graphics(HWND hwnd);
	~Graphics();

	void RenderBegin();
	void RenderEnd();

	ComPtr<ID3D11Device> GetDevice() { return _device; }
	ComPtr<ID3D11DeviceContext> GetDeviceContext() { return _deviceContext; }

private:
	void CreateDeviceAndSwapChain();
	void CreateRenderTargetView();
	void SetViewport();
private:
	HWND _hwnd;

private:
	// Device & SwapChain
	ComPtr<ID3D11Device> _device; // GPU�� �����ϴ� ��ǥ (���ҽ� ����)
	ComPtr<ID3D11DeviceContext> _deviceContext; // ������ ���������� �ܰ迡�� �� ���ҽ��� �����ִ� ����
	ComPtr<IDXGISwapChain> _swapChain; // ���� ���۸��� ���� �ĸ���ۿ� �ٰ� �츮�� �׸��� �׷��ָ�
	// �� �ĸ���� ������ ������۷� ������ ��Ӻ��縦 ���� (Present �Լ��� �� ������ ������ ��Ӻ��� �Ͼ)

	// RTV
	ComPtr<ID3D11RenderTargetView> _renderTargetView;
	// �츮�� ������� ����ü���� �ĸ���ۿ��ٰ� �׸��� �׷� �ּ��� ��� ����� ������ ����
	// ���۸� �����ϴ� view ����

	// Misc
	D3D11_VIEWPORT _viewport = { 0 }; // ȭ���� �����ϴ� ����ü
	float _clearColor[4] = { 0.5f, 0.5f, 0.5f, 0.5f };

};

