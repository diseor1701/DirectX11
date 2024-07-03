#include "pch.h"
#include "BaseController.h"

void BaseController::Awake()
{
    Init();
}

bool BaseController::Init()
{
    if (_init)
        return false;

    _init = true;
    return true;
}

void BaseController::Update()
{
    UpdateController();
}

void BaseController::UpdateController()
{
}
