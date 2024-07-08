#include "pch.h"

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
	}

	GetTransform()->SetPosition(pos);

}

void PlayerController::OnDead()
{

}


