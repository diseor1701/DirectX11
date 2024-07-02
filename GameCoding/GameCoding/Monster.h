#pragma once

#include "MonoBehaviour.h"
class Monster : public MonoBehaviour
{
public:
	Monster();
	virtual ~Monster();

	void Init();
	void Update();
};

