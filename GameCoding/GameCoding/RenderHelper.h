#pragma once
struct CameraData
{
	Matrix matView = Matrix::Identity;
	Matrix matProjection = Matrix::Identity;
};

struct TransformData
{
	Matrix matWorld = Matrix::Identity;
};

struct AnimationData
{
	Vec2 spriteOffset;
	Vec2 spriteSize;
	Vec2 textureSize;
	float useAnimation;
	// 16바이트 정렬을 위해 쓰레기값
	float padding;
};