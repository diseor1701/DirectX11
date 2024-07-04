#include "pch.h"
#include "Scene.h"

void Scene::Start()
{
	for (const shared_ptr<GameObject>& gameObejct : _gameObjects)
	{
		gameObejct->Start();
	}
}

void Scene::Update()
{
	for (const shared_ptr<GameObject>& gameObejct : _gameObjects)
	{
		gameObejct->Update();
	}
}

void Scene::LateUpdate()
{
	for (const shared_ptr<GameObject>& gameObejct : _gameObjects)
	{
		gameObejct->LateUpdate();
	}
}

void Scene::Add(shared_ptr<GameObject> gameObject)
{
	_gameObjects.push_back(gameObject);
}

void Scene::Remove(shared_ptr<GameObject> gameObject)
{
	auto findIt = std::find(_gameObjects.begin(), _gameObjects.end(), gameObject);
	if (findIt != _gameObjects.end())
		_gameObjects.erase(findIt);
}
