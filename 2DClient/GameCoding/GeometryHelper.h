#pragma once
#include "Geometry.h"
#include "VertexData.h"

class GeometryHelper
{
public:
	static void CreateRectangle(shared_ptr<Geometry<VertexColorData>> geometry, Color color);
	static void CreateRectangle(shared_ptr<Geometry<VertexTextureData>> geometry);

	static void CreateMap(shared_ptr<Geometry<VertexTextureData>> geometry, int32 sizeX, int32 sizeY);
};

