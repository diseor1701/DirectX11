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
	HWND _hwnd;
	shared_ptr<Graphics> _graphics;
	shared_ptr<Pipeline> _pipeline;

private:
	shared_ptr<Geometry<VertexTextureData>> _geometry;
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	// 중복되서 사용되는 정점의 개수를 줄이기 위해서 사용한다.
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

	Vec3 _localPosition = { 0.f, 0.f, 0.f };
	Vec3 _localRotation = { 0.f, 0.f, 0.f };
	Vec3 _localScale = { 1.f, 1.f, 1.f };
};

 