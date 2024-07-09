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


protected:
	Vec3 _moveDir = Vec3{ 0.f, 0.f, 0.f };
	float _speed = 5.f;

};

