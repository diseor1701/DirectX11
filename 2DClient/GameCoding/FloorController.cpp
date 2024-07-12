#include "pch.h"
#include "Game.h"
#include "FloorController.h"
#include "TimeManager.h"

void FloorController::Init()
{
}

void FloorController::Update()
{
	float dt = TIME->GetDeltaTime();

	Vec3 pos = GetTransform()->GetPosition();
	
	pos -= GetTransform()->GetRight() * 100 * _speed * dt;

	if (pos.x < -1300.f)
		pos.x = 400.f;

	GetTransform()->SetPosition(pos);
}
