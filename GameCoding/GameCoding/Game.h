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
	// 만든 후면 버퍼를 묘사하는 존재
	// View : 어떤 자원에서 대해서 태그를 달아가지고 
	// 나중에 GPU에 친절하게 설명하기 위한 부연 설명같은 것

	void SetViewport();

private:
	void CreateGeometry();		// 기하학적인 도형 만듦
	void CreateInputLayout();	// 그 도형에 대한 설명서 작성
	void CreateVS();			
	void CreatePS();
	// GPU가 해야하는 일감만들기

	void LoadShaderFromFile(const wstring& path, const string& name,  const string& version, ComPtr<ID3DBlob>& blob);
private:
	HWND _hwnd;
	uint32 _width = 0;
	uint32 _height = 0;

private:
	// Device & SwapChain
	ComPtr<ID3D11Device> _device; // 스마트포인터
	ComPtr<ID3D11DeviceContext> _deviceContext;
	ComPtr<IDXGISwapChain> _swapChain;
	
	// RTV
	ComPtr<ID3D11RenderTargetView> _renderTargetView;
	D3D11_VIEWPORT _viewport = { 0 }; // 화면을 묘사하는 구조체

	float _clearColor[4] = { 0.f, 0.f, 0.f, 0.f };

private:
	// Geometry
	vector<Vertex> _vertices;
	ComPtr<ID3D11Buffer> _vertexBuffer = nullptr;
	ComPtr<ID3D11InputLayout> _inputLayout = nullptr;

	// VS
	ComPtr<ID3D11VertexShader> _vertexShader = nullptr;
	ComPtr<ID3DBlob> _vsBlob = nullptr;
	// PS
	ComPtr<ID3D11PixelShader> _pixelShader = nullptr;
	ComPtr<ID3DBlob> _psBlob = nullptr;

	// [ CPU <-> RAM ] [ GPU <-> VRAM ]
};

 