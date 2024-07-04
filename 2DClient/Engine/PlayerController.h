#pragma once
#include "CreatureController.h"

class PlayerController : public CreatureController
{
	using Super = CreatureController;
public:

	virtual bool Init() override;
	virtual void Update() override;
	void MovePlayer();
	virtual void OnDamaged() override;
	virtual void OnDead() override;

	Vec3 GetMoveDir() { return _moveDir; }
	void SetMoveDir(Vec3 moveDir) { moveDir.Normalize(); _moveDir = moveDir; }

protected:
	Vec3 _moveDir = Vec3{ 0.f, 0.f, 0.f };
};

