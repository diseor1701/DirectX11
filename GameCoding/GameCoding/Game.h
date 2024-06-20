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
	void CreateGeometry();		// ���������� ���� ����
	
	void CreateInputLayout();	
	// �� ������ ���� ���� �ۼ� (vertex ��� �ְ� ��� ���ܸԾ����� �����ϴ� �ܰ�)
	
	void CreateVS();			
	void CreatePS();
	// GPU�� �ؾ��ϴ� �ϰ������

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
	ComPtr<ID3D11Device> _device; // GPU�� �����ϴ� ��ǥ (���ҽ� ����)
	ComPtr<ID3D11DeviceContext> _deviceContext; // ������ ���������� �ܰ迡�� �� ���ҽ��� �����ִ� ����
	ComPtr<IDXGISwapChain> _swapChain; // ���� ���۸��� ���� �ĸ���ۿ� �ٰ� �츮�� �׸��� �׷��ָ�
	// �� �ĸ���� ������ ������۷� ������ ��Ӻ��縦 ���� (Present �Լ��� �� ������ ������ ��Ӻ��� �Ͼ)
	
	// RTV
	ComPtr<ID3D11RenderTargetView> _renderTargetView;
	// �츮�� ������� ����ü���� �ĸ���ۿ��ٰ� �׸��� �׷� �ּ��� ��� ����� ������ ����

	// Misc
	D3D11_VIEWPORT _viewport = { 0 }; // ȭ���� �����ϴ� ����ü
	float _clearColor[4] = { 0.3f, 0.5f, 0.6f, 0.2f };

private:
	// Geometry (mesh)
	vector<Vertex> _vertices;
	ComPtr<ID3D11Buffer> _vertexBuffer = nullptr;
	vector<uint32> _indices;
	ComPtr<ID3D11Buffer> _indexBuffer = nullptr;
	ComPtr<ID3D11InputLayout> _inputLayout = nullptr;
	// �ε��� ���۴� �ﰢ���� ������ �Ѱ��ִ� �� ������ ������ �� �� ���ִ�.
	// �޸� ������ �׻� ȿ�������� �۾��� �� �ִ�. (�� �ѱ��� �ʰ� �Ϻθ� �ѱ�� ����)

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

 