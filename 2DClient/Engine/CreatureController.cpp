#include "pch.h"
#include "CreatureController.h"

bool CreatureController::Init()
{
	if (Super::Init() == false)
		return false;


	return true;
}

void CreatureController::Update()
{
	Super::Update();
}

void CreatureController::OnDamaged()
{
}

void CreatureController::OnDead()
{
}
