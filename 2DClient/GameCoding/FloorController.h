#pragma once
#include "MonoBehaviour.h"
class FloorController : public MonoBehaviour
{
	using Super = MonoBehaviour;

public:
	virtual void Init();
	virtual void Update();

private:
	float _speed = 5.f;
};

