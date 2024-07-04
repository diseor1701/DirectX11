#pragma once

class GameObject;

class Scene
{
public:
	virtual void Start();
	virtual void Update();
	virtual void LateUpdate();

	virtual void Add(shared_ptr<GameObject> object);
	virtual void Remove(shared_ptr<GameObject> object);

	const vector<shared_ptr<GameObject>>& GetGameObjects() { return _gameObjects; }
private:
	vector<shared_ptr<GameObject>> _gameObjects;
};

