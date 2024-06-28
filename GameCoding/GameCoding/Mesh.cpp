#include "pch.h"
#include "Mesh.h"

Mesh::Mesh(ComPtr<ID3D11Device> device) 
	: Super(ResourceType::Mesh), _device(device)
{
}

Mesh::~Mesh()
{
}

void Mesh::CreateDefaultRectangle()
{
	_geometry = make_shared<Geometry<VertexTextureData>>();
	GeometryHelper::CreateRectangle(_geometry);

	_vertexBuffer = make_shared<VertexBuffer>(_device);
	_vertexBuffer->Create(_geometry->GetVertices());

	// 정점이 너무 많아지면 중복현상이 일어나니까 정점은 한번만 알려주고 그 정점의 인덱스를 묶어서 삼각형을 그림
	_indexBuffer = make_shared<IndexBuffer>(_device);
	_indexBuffer->Create(_geometry->GetIndices());
}
