#include "pch.h"
#include "Game.h"
#include "GravityController.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "PlayerController.h"

void PlayerController::Init()
{
	_speed = 5.0f;
}

void PlayerController::Update() 
{
	MovePlayer();
}

void PlayerController::MovePlayer()
{
	float dt = TIME->GetDeltaTime();

	Vec3 pos = GetTransform()->GetPosition();
	Vec3 rotation = GetTransform()->GetLocalRotation();

	if (INPUT->GetButton(KEY_TYPE::SPACE))
	{
		pos += Vec3(0.f, 150.f, 0.f) * _speed * dt;
		rotation += Vec3(0.f, 0.f, 0.15f);

		if (pos.y > 400)
			pos.y = 400;

		if (rotation.z > 0.7f)
			rotation.z = 0.7f;
		GetGameObject()->GetGravityController()->SetFallSpeed(0.5f);
		GetGameObject()->GetGravityController()->SetOffYDelta(-0.01f);
	}
	else 
	{
		rotation -= Vec3(0.f, 0.f, 0.006f);

		if (rotation.z < -1.f)
			rotation.z = -1.f;
	}
	GetTransform()->SetPosition(pos);
	GetTransform()->SetRotation(rotation);
}


void PlayerController::OnDead()
{

}


