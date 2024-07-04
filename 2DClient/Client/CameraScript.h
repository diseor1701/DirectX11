#pragma once
#include "MonoBehaviour.h"

class GameObject;
class CameraScript : public MonoBehaviour
{
public:
	virtual void Start() override;
	virtual void LateUpdate() override;

	void SetTarget(shared_ptr<GameObject> target) { _target = target; }

	float _speed = 10.f;
	shared_ptr<GameObject> _target;
};

