#include "pch.h"
#include "GameObject.h"

GameObject::GameObject(ComPtr<ID3D11Device> device, ComPtr<ID3D11DeviceContext> deviceContext)
	: _device(device)
{
	_geometry = make_shared<Geometry<VertexTextureData>>();
	// VertexData
	GeometryHelper::CreateRectangle(_geometry);

	_vertexBuffer = make_shared<VertexBuffer>(device);
	_vertexBuffer->Create(_geometry->GetVertices());

	// 정점이 너무 많아지면 중복현상이 일어나니까 정점은 한번만 알려주고 그 정점의 인덱스를 묶어서 삼각형을 그림
	_indexBuffer = make_shared<IndexBuffer>(device);
	_indexBuffer->Create(_geometry->GetIndices());

	_vertexShader = make_shared<VertexShader>(device);
	_vertexShader->Create(L"Default.hlsl", "VS", "vs_5_0");

	// 우리가 만들어준 버텍스 버퍼가 어떤 식으로 되어 있는지를 묘사하는 역할
	_inputLayout = make_shared<InputLayout>(device);
	_inputLayout->Create(VertexTextureData::descs, _vertexShader->GetBlob());

	_pixelShader = make_shared<PixelShader>(device);
	_pixelShader->Create(L"Default.hlsl", "PS", "ps_5_0");

	_rasterizerState = make_shared<RasterizerState>(device);
	_rasterizerState->Create();

	_blendState = make_shared<BlendState>(device);
	_blendState->Create();

	_constantBuffer = make_shared<ConstantBuffer<TransformData>>(device, deviceContext);
	_constantBuffer->Create();

	_texture1 = make_shared<Texture>(device);
	_texture1->Create(L"Skeleton.png");

	_samplerState = make_shared<SamplerState>(device);
	_samplerState->Create();
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	//// Scale Rotation Translation
	//_localPosition.x += 0.001f;

	//Matrix matScale = Matrix::CreateScale(_localScale / 3);
	//Matrix matRotation = Matrix::CreateRotationX(_localRotation.x);
	//matRotation *= Matrix::CreateRotationY(_localRotation.y);
	//matRotation *= Matrix::CreateRotationZ(_localRotation.z);
	//Matrix matTranslation = Matrix::CreateTranslation(_localPosition);

	//Matrix matWorld = matScale * matRotation * matTranslation; // SRT
	//_transformData.matWorld = matWorld;

	//_constantBuffer->CopyData(_transformData);
}

void GameObject::Render(shared_ptr<Pipeline> pipeline)
{
	// IA - VS - RS - PS - OM
	{
		PipelineInfo info;
		info.inputLayout = _inputLayout;
		info.vertexShader = _vertexShader;
		info.rasterizerState = _rasterizerState;
		info.pixelShader = _pixelShader;
		info.blendState = _blendState;

		pipeline->UpdatePipeline(info);

		pipeline->SetVertexBuffer(_vertexBuffer);
		pipeline->SetIndexBuffer(_indexBuffer);
		pipeline->SetConstantBuffer(0, SS_VertexShader, _constantBuffer);
		pipeline->SetTexture(0, SS_PixelShader, _texture1);
		pipeline->SetSamplerState(0, SS_PixelShader, _samplerState);

		pipeline->DrawIndexed(_geometry->GetIndexCount(), 0, 0);
	}
}
