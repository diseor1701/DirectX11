#pragma once
#include "MonoBehaviour.h"

enum class ObjectType
{
	None,
	Player,
	Monster,
	Projectile,
	Env,
};

class BaseController : public MonoBehaviour
{
public:

	virtual void Awake() override;

	bool _init = false;
	
	virtual bool Init();

	virtual void Update() override;

	virtual void UpdateController();
};

