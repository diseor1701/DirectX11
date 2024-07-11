#pragma once
#include "MonoBehaviour.h"
#include "Types.h"


class PlayerController : public MonoBehaviour
{
	using Super = MonoBehaviour;
public:
	virtual void Init();
	virtual void Update();
	void MovePlayer();
	void OnDead();

protected:
	float _speed = 7.f;
};

