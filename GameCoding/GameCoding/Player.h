#pragma once

#include "MonoBehaviour.h"

class Player : public MonoBehaviour
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();

};

