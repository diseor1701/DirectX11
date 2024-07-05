#include "pch.h"
#include "Animation.h"
#include "Texture.h"

Animation::Animation() : Super(ResourceType::Animation)
{

}

Animation::~Animation()
{

}

Vec2 Animation::GetTextureSize()
{
	return _texture->GetSize();
}

const Keyframe& Animation::GetKeyframe(int32 index)
{
	return _keyframes[index];
}

int32 Animation::GetKeyframeCount()
{
	return static_cast<int32>(_keyframes.size());
}

void Animation::AddKeyframe(const Keyframe& keyframe)
{
	_keyframes.push_back(keyframe);
}
