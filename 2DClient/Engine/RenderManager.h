#pragma once
#include "ConstantBuffer.h"

class Shader;

struct AnimationData
{
	Vec2 spriteOffset;
	Vec2 spriteSize;
	Vec2 textureSize;
	float useAnimation;
	float padding;
};


class RenderManager
{
	DECLARE_SINGLE(RenderManager);

public:
	void Init(shared_ptr<Shader> shader);
	void Update();

	void PushAnimationData(const AnimationData& desc);

	void GatherRenderableObjects();
	void RenderObjects();
private:
	shared_ptr<Shader> _shader;

private:
	vector<shared_ptr<GameObject>> _renderObjects;

	AnimationData _animationData;
	shared_ptr<ConstantBuffer<AnimationData>> _animationBuffer;
	ComPtr<ID3DX11EffectConstantBuffer> _animationEffectBuffer;
};

