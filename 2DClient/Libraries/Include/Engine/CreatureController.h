#pragma once
#include "BaseController.h"

class CreatureController : public BaseController
{
	using Super = BaseController;
public:
	virtual bool Init() override;
	virtual void Update() override;
	virtual void OnDamaged();
	virtual void OnDead();

	int32 GetHp() { return _hp; }
	void SetHp(int32 hp) { _hp = hp; }
	int32 GetMaxHp() { return _maxHp; }
	void SetMaxHp(int32 maxHp) { _maxHp = maxHp; }
	float GetSpeed() { return _speed; }
	void SetSpeed(float speed) { _speed = speed; }


protected:
	int32 _hp = 100;
	int32 _maxHp = 100;
	float _speed = 2.0f;
};

