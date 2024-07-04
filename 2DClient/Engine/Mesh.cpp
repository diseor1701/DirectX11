#include "pch.h"
#include "Mesh.h"
#include "GeometryHelper.h"

Mesh::Mesh()  : Super(ResourceType::Mesh)
{

}

Mesh::~Mesh()
{

}

void Mesh::CreateMap(int32 sizeX, int32 sizeY)
{
	_geometry = make_shared<Geometry<VertexTextureData>>();
	GeometryHelper::CreateMap(_geometry, sizeX, sizeY);
	CreateBuffers();
}
void Mesh::CreateQuad()
{
	_geometry = make_shared<Geometry<VertexTextureData>>();
	GeometryHelper::CreateQuad(_geometry);
	CreateBuffers();
}

void Mesh::CreateCube()
{
	_geometry = make_shared<Geometry<VertexTextureData>>();
	GeometryHelper::CreateCube(_geometry);
	CreateBuffers();
}

void Mesh::CreateGrid(int32 sizeX, int32 sizeY)
{
	_geometry = make_shared<Geometry<VertexTextureData>>();
	GeometryHelper::CreateGrid(_geometry, sizeX, sizeY);
	CreateBuffers();
}

void Mesh::CreateSphere()
{
	_geometry = make_shared<Geometry<VertexTextureData>>();
	GeometryHelper::CreateSphere(_geometry);
	CreateBuffers();
}

void Mesh::CreateBuffers()
{
	_vertexBuffer = make_shared<VertexBuffer>();
	_vertexBuffer->Create(_geometry->GetVertices());
	_indexBuffer = make_shared<IndexBuffer>();
	_indexBuffer->Create(_geometry->GetIndices());
}
