#include "pch.h"
#include "GravityController.h"
#include "TimeManager.h"
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

	if (INPUT->GetButton(KEY_TYPE::SPACE))
	{
		pos += GetTransform()->GetUp() * _speed * dt;

		float fallSpeed = GetGameObject()->GetGravityController()->GetFallSpeed();
		float offYDelta = GetGameObject()->GetGravityController()->GetOffYDelta();
		float gravityPower = GetGameObject()->GetGravityController()->GetGravityPower();

		fallSpeed -= dt * gravityPower * 5;
		offYDelta += dt * fallSpeed;
		GetGameObject()->GetGravityController()->SetFallSpeed(fallSpeed);
		GetGameObject()->GetGravityController()->SetOffYDelta(offYDelta);
	}

	GetTransform()->SetPosition(pos);
}


void PlayerController::OnDead()
{

}


