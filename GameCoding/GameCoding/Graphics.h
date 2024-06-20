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
	ComPtr<ID3D11Device> _device; // GPU를 묘사하는 대표 (리소스 생성)
	ComPtr<ID3D11DeviceContext> _deviceContext; // 렌더링 파이프라인 단계에서 그 리소스를 묶어주는 역할
	ComPtr<IDXGISwapChain> _swapChain; // 더블 버퍼링을 통해 후면버퍼에 다가 우리가 그림을 그려주면
	// 그 후면버퍼 내용을 전면버퍼로 빠르게 고속복사를 해줌 (Present 함수를 빵 때리는 순간에 고속복사 일어남)

	// RTV
	ComPtr<ID3D11RenderTargetView> _renderTargetView;
	// 우리가 만들어준 스왑체인의 후면버퍼에다가 그림을 그려 주세요 라는 명령을 내리기 위함
	// 버퍼를 묘사하는 view 느낌

	// Misc
	D3D11_VIEWPORT _viewport = { 0 }; // 화면을 묘사하는 구조체
	float _clearColor[4] = { 0.5f, 0.5f, 0.5f, 0.5f };

};

