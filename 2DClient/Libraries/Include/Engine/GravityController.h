#pragma once
#include "MonoBehaviour.h"

static class GravityController : public MonoBehaviour
{
public:
	void Init();
	void Update();

	float GetFallSpeed() { return _fallSpeed; }
	void SetFallSpeed(float fallSpeed) { _fallSpeed = fallSpeed; }

	float GetOffYDelta() { return _offYDelta; }
	void SetOffYDelta(float offYDelta) { _offYDelta = offYDelta; }

	float GetGravityPower() { return _gravityPower; }
	void SetGravityPower(float gravityPower) { _gravityPower = gravityPower; }
private:
	float MaxSpeedPerSecond = 0.5f;
	float _gravityPower = 0.01f;
	float _fallSpeed = 0.f;
	float _offYDelta = 0.f;
};

