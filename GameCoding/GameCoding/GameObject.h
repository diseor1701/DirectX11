#pragma once
class GameObject
{
public:
	GameObject(ComPtr<ID3D11Device> device, ComPtr<ID3D11DeviceContext> deviceContext);
	~GameObject();

	void Update();
	void Render(shared_ptr<Pipeline> pipeline);

private:
	ComPtr<ID3D11Device> _device;

	shared_ptr<Geometry<VertexTextureData>> _geometry;
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	// �ߺ��Ǽ� ���Ǵ� ������ ������ ���̱� ���ؼ� ����Ѵ�.
	shared_ptr<InputLayout> _inputLayout;


	// VS
	shared_ptr<VertexShader> _vertexShader;
	// RAS
	shared_ptr<RasterizerState> _rasterizerState;

	// PS
	shared_ptr<PixelShader> _pixelShader;
	shared_ptr<SamplerState> _samplerState;
	// SRV
	shared_ptr<Texture> _texture1;
	// [ CPU <-> RAM ] [ GPU <-> VRAM ]
	// OM
	shared_ptr<BlendState> _blendState;
private:
	// SRT
	TransformData _transformData;
	shared_ptr<ConstantBuffer<TransformData>> _constantBuffer;

};

