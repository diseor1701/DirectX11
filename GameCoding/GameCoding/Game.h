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
	
	void CreateInputLayout();	
	// 그 도형에 대한 설명서 작성 (vertex 라는 애가 어떻게 생겨먹었는지 묘사하는 단계)
	
	void CreateVS();			
	void CreatePS();
	// GPU가 해야하는 일감만들기

	void CreateRasterizerState();
	void CraeteSamplerState();
	void CreateBlendState();

	void CreateSRV();
	// shader-resource-view

	void CreateConstantBuffer();

	void LoadShaderFromFile(const wstring& path, const string& name,  const string& version, ComPtr<ID3DBlob>& blob);
private:
	HWND _hwnd;
	uint32 _width = 0;
	uint32 _height = 0;

private:
	// Device & SwapChain
	ComPtr<ID3D11Device> _device; // GPU를 묘사하는 대표 (리소스 생성)
	ComPtr<ID3D11DeviceContext> _deviceContext; // 렌더링 파이프라인 단계에서 그 리소스를 묶어주는 역할
	ComPtr<IDXGISwapChain> _swapChain; // 더블 버퍼링을 통해 후면버퍼에 다가 우리가 그림을 그려주면
	// 그 후면버퍼 내용을 전면버퍼로 빠르게 고속복사를 해줌 (Present 함수를 빵 때리는 순간에 고속복사 일어남)
	
	// RTV
	ComPtr<ID3D11RenderTargetView> _renderTargetView;
	// 우리가 만들어준 스왑체인의 후면버퍼에다가 그림을 그려 주세요 라는 명령을 내리기 위함

	// Misc
	D3D11_VIEWPORT _viewport = { 0 }; // 화면을 묘사하는 구조체
	float _clearColor[4] = { 0.3f, 0.5f, 0.6f, 0.2f };

private:
	// Geometry (mesh)
	vector<Vertex> _vertices;
	ComPtr<ID3D11Buffer> _vertexBuffer = nullptr;
	vector<uint32> _indices;
	ComPtr<ID3D11Buffer> _indexBuffer = nullptr;
	ComPtr<ID3D11InputLayout> _inputLayout = nullptr;
	// 인덱스 버퍼는 삼각형의 개수를 넘겨주는 그 정점의 개수를 줄 일 수있다.
	// 메모리 쪽으로 항상 효율적으로 작업할 수 있다. (다 넘기지 않고 일부만 넘기기 가능)

	// VS
	ComPtr<ID3D11VertexShader> _vertexShader = nullptr;
	ComPtr<ID3DBlob> _vsBlob = nullptr;

	// RAS
	ComPtr<ID3D11RasterizerState> _rasterizerState = nullptr;

	ComPtr<ID3D11SamplerState> _samplerState = nullptr;
	ComPtr<ID3D11BlendState> _blendState = nullptr;

	// PS
	ComPtr<ID3D11PixelShader> _pixelShader = nullptr;
	ComPtr<ID3DBlob> _psBlob = nullptr;

	// SRV
	ComPtr<ID3D11ShaderResourceView> _shaderResourceView = nullptr;
	ComPtr<ID3D11ShaderResourceView> _shaderResourceView2 = nullptr;

	// [ CPU <-> RAM ] [ GPU <-> VRAM ]

private:
	// SRT
	TransformData _transformData;
	ComPtr<ID3D11Buffer> _constantBuffer;

	Vec3 _localPosition = { 0.f, 0.f, 0.f };
	Vec3 _localRotation = { 0.f, 0.f, 0.f };
	Vec3 _localScale = { 1.f, 1.f, 1.f };
};

 