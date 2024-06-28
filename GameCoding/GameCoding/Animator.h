#pragma once
#include "Component.h"
#include "Animation.h"

class Animator : public Component
{
	using Super = Component;

public:
	Animator();
	virtual ~Animator();

	void Init();
	void Update();
	
	shared_ptr<Animation> GetCurrentAnimation() { return _currentAnimator; }
	const Keyframe& GetCurrentKeyframe() { return _currentAnimator->GetKeyframe(_currentKeyframeIndex); }

	void SetAnimation(shared_ptr<Animation> animation) { _currentAnimator = animation; }
private:
	float _sunTime = 0.0f;
	int32 _currentKeyframeIndex = 0;
	shared_ptr<Animation> _currentAnimator;
};

