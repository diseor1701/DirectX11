#pragma once
#include "Component.h"
class Map : public Component
{
	using Super = Component;

public:
	Map();
	virtual ~Map();

	virtual void Update() override;
};

