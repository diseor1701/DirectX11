#include "pch.h"
#include "Game.h"
#include "GravityController.h"
#include "TimeManager.h"
void GravityController::Init()
{
	_fallSpeed = 0.f;
	_offYDelta = 0.f;
}

void GravityController::Update()
{
	float dt = TIME->GetDeltaTime();
	_fallSpeed += dt * _gravityPower;
	if (_fallSpeed >= MaxSpeedPerSecond)
		_fallSpeed = MaxSpeedPerSecond;

	_offYDelta -= _fallSpeed * TIME->GetDeltaTime();
	shared_ptr<Transform> transform = GetTransform();
	transform->SetPosition(transform->GetPosition() + Vec3(0.f, 1.0f, 0.f) * _offYDelta);

}