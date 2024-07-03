#include "pch.h"
#include "PlayerController.h"

bool PlayerController::Init()
{
	if (Super::Init() == false)
		return false;

	_speed = 5.0f;

	return true;
}

void PlayerController::Update() 
{
}

void PlayerController::MovePlayer()
{
	float dt = TIME->GetDeltaTime();

	Vec3 pos = GetTransform()->GetPosition();

	if (INPUT->GetButton(KEY_TYPE::W))
		pos += GetTransform()->GetUp() * _speed * dt;

	if (INPUT->GetButton(KEY_TYPE::S))
		pos -= GetTransform()->GetUp() * _speed * dt;

	if (INPUT->GetButton(KEY_TYPE::A))
		pos -= GetTransform()->GetRight() * _speed * dt;

	if (INPUT->GetButton(KEY_TYPE::D))
		pos += GetTransform()->GetRight() * _speed * dt;

	GetTransform()->SetPosition(pos);

}
void PlayerController::OnDamaged()
{
}

void PlayerController::OnDead()
{
}


