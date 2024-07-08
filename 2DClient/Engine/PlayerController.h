#pragma once
#include "MonoBehaviour.h"

class PlayerController : public MonoBehaviour
{
	using Super = MonoBehaviour;
public:

	virtual void Init();
	virtual void Update();
	void MovePlayer();
	virtual void OnDead();

	Vec3 GetMoveDir() { return _moveDir; }
	void SetMoveDir(Vec3 moveDir) { moveDir.Normalize(); _moveDir = moveDir; }


	//float GetFallSpeed() { return _fallSpeed; }
	//void SetFallSpeed(float fallSpeed) { _fallSpeed = fallSpeed; }

	//float GetOffYDelta() { return _offYDelta; }
	//void SetOffYDelta(float offYDelta) { _offYDelta = offYDelta; }
protected:
	Vec3 _moveDir = Vec3{ 0.f, 0.f, 0.f };
	float _speed = 5.f;

	//float _fallSpeed = 0.f;
	//float _offYDelta = 0.f;

};

