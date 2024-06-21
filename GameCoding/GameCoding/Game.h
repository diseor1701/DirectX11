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

	shared_ptr<Graphics> _graphics;

private:
	// Geometry (mesh)
	vector<Vertex> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	//ComPtr<ID3D11Buffer> _vertexBuffer = nullptr;
	vector<uint32> _indices;
	shared_ptr<IndexBuffer> _indexBuffer;
	// 중복되서 사용되는 정점의 개수를 줄이기 위해서 사용한다.
	shared_ptr<InputLayout> _inputLayout;

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

 