#pragma once
#include "PlayerController.h"

class GravityController : public PlayerController
{
public:
	virtual void Init();
	virtual void Update();

	float GetFallSpeed() { return _fallSpeed; }
	void SetFallSpeed(float fallSpeed) { _fallSpeed = fallSpeed; }

	float GetOffYDelta() { return _offYDelta; }
	void SetOffYDelta(float offYDelta) { _offYDelta = offYDelta; }
private:
	float MaxSpeedPerSecond = 0.5f;
	float _fallSpeed = 0.f;
	float _gravityPower = 0.01f;
	float _offYDelta = 0.f;
};

