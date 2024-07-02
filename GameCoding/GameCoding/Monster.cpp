#include "pch.h"
#include "Monster.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::Init()
{
}

void Monster::Update()
{
	float dt = TIME->GetDeltaTime();
	shared_ptr<Transform> transform = GetTransform();
	Vec3 _translation = transform->GetLocalPosition();

	if (INPUT->GetButton(KEY_TYPE::A))
	{
		_translation.x -= 3.f * dt;
	}
	else if (INPUT->GetButton(KEY_TYPE::D))
	{
		_translation.x += 3.f * dt;
	}
	else if (INPUT->GetButton(KEY_TYPE::W))
	{
		_translation.y += 3.f * dt;
	}
	else if (INPUT->GetButton(KEY_TYPE::S))
	{
		_translation.y -= 3.f * dt;
	}


	// SRT
	transform->SetLocalPosition(_translation);
}
