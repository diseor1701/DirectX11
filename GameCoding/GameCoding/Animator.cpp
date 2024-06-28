#include "pch.h"
#include "Game.h"
#include "Animator.h"
#include "TimeManager.h"

Animator::Animator() : Super(ComponentType::Animator)
{
}

Animator::~Animator()
{
}

void Animator::Init()
{
}

void Animator::Update()
{
	shared_ptr<Animation> animation = GetCurrentAnimation();

	if (animation == nullptr)
		return;

	const Keyframe& keyframe = _currentAnimator->GetKeyframe(_currentKeyframeIndex);

	float deltaTime = TIME->GetDeltaTime();
	_sunTime += deltaTime;

	if (_sunTime >= keyframe.time)
	{
		_currentKeyframeIndex++;
		int32 totalCount = animation->GetKeyframeCount();

		if (_currentKeyframeIndex >= totalCount)
		{
			if (animation->IsLoop())
				_currentKeyframeIndex = 0;
			else
				_currentKeyframeIndex = totalCount - 1;
		}
		_sunTime = 0;
	}
}

