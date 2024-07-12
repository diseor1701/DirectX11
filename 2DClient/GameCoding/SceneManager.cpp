#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GameObject.h"
#include "Camera.h"
#include "Transform.h"
#include "MeshRenderer.h"
#include "ResourceManager.h"
#include "Game.h"
#include "Mesh.h"
#include "Animator.h"
#include "PlayerController.h"
#include "GravityController.h"
#include "FloorController.h"

SceneManager::SceneManager(shared_ptr<Graphics> graphics)
	: _graphics(graphics)
{

}

void SceneManager::Init()
{
	if (_activeScene == nullptr)
		return;

	_activeScene->Awake();
	_activeScene->Start();
}

void SceneManager::Update()
{
	if (_activeScene == nullptr)
		return;

	_activeScene->Update();
	_activeScene->LateUpdate(); 
	
	_activeScene->FixedUpdate();	
}

void SceneManager::LoadScene(wstring sceneName)
{
	// Resource

	_activeScene = LoadTestScene();
	Init();
}

std::shared_ptr<Scene> SceneManager::LoadTestScene()
{
	shared_ptr<Scene> scene = make_shared<Scene>();

	
	// Camera
	{
		shared_ptr<GameObject> camera = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
		{
			camera->GetOrAddTransform();
			camera->AddComponent(make_shared<Camera>());
			scene->AddGameObject(camera);
		}
	}

	// Map
	{
		shared_ptr<GameObject> map = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
		map->GetOrAddTransform()->SetPosition(Vec3(-225.f, -400.f, 0.f));
		{
			auto meshRenderer = make_shared<MeshRenderer>(_graphics->GetDevice(), _graphics->GetDeviceContext());
			map->AddComponent(meshRenderer);
			auto material = RESOURCES->Get<Material>(L"Map");
			meshRenderer->SetMaterial(material);
			auto mesh = RESOURCES->Get<Mesh>(L"Map");
			meshRenderer->SetMesh(mesh);
		}
		scene->AddGameObject(map);
	}

	// Floor1
	{		
		shared_ptr<GameObject> floor1 = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
		floor1->GetOrAddTransform()->SetPosition(Vec3(-450.f, -400.f, 0.f));
		{
			auto meshRenderer = make_shared<MeshRenderer>(_graphics->GetDevice(), _graphics->GetDeviceContext());
			floor1->AddComponent(meshRenderer);
			auto material = RESOURCES->Get<Material>(L"Floor");
			meshRenderer->SetMaterial(material);
			auto mesh = RESOURCES->Get<Mesh>(L"Floor");
			meshRenderer->SetMesh(mesh);
		}
		{
			floor1->AddComponent(make_shared<FloorController>());
		}
		scene->AddGameObject(floor1);
	}
	// Floor2
	{
		shared_ptr<GameObject> floor2 = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
		floor2->GetOrAddTransform()->SetPosition(Vec3(400.f, -400.f, 0.f));
		{
			auto meshRenderer = make_shared<MeshRenderer>(_graphics->GetDevice(), _graphics->GetDeviceContext());
			floor2->AddComponent(meshRenderer);
			auto material = RESOURCES->Get<Material>(L"Floor");
			meshRenderer->SetMaterial(material);
			auto mesh = RESOURCES->Get<Mesh>(L"Floor");
			meshRenderer->SetMesh(mesh);
		}
		{
			floor2->AddComponent(make_shared<FloorController>());
		}
		scene->AddGameObject(floor2);
	}

	// Pipe1
	{
		shared_ptr<GameObject> Pipe1 = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
		//Pipe1->GetOrAddTransform()->SetPosition(Vec3(100.f, 10.f, 0.f));
		{
			auto meshRenderer = make_shared<MeshRenderer>(_graphics->GetDevice(), _graphics->GetDeviceContext());
			Pipe1->AddComponent(meshRenderer);
			auto material = RESOURCES->Get<Material>(L"Pipe1");
			meshRenderer->SetMaterial(material);
			auto mesh = RESOURCES->Get<Mesh>(L"Pipe");
			meshRenderer->SetMesh(mesh);
		}
		scene->AddGameObject(Pipe1);
	}
	// Pipe2
	{
		shared_ptr<GameObject> Pipe2 = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
		//Pipe2->GetOrAddTransform()->SetPosition(Vec3(50.f, -250.f, 0.f));
		{
			auto meshRenderer = make_shared<MeshRenderer>(_graphics->GetDevice(), _graphics->GetDeviceContext());
			Pipe2->AddComponent(meshRenderer);
			auto material = RESOURCES->Get<Material>(L"Pipe2");
			meshRenderer->SetMaterial(material);
			auto mesh = RESOURCES->Get<Mesh>(L"Pipe");
			meshRenderer->SetMesh(mesh);

		}
		scene->AddGameObject(Pipe2);
	}

	// Player
	{
		shared_ptr<GameObject> player = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
		player->GetOrAddTransform()->SetLocalScale(Vec3(30.f, 40.f, 0.f));
		{
			auto meshRenderer = make_shared<MeshRenderer>(_graphics->GetDevice(), _graphics->GetDeviceContext());
			player->AddComponent(meshRenderer);
			auto material = RESOURCES->Get<Material>(L"Player");
			meshRenderer->SetMaterial(material);
			auto mesh = RESOURCES->Get<Mesh>(L"Rectangle");
			meshRenderer->SetMesh(mesh);
		}
		{
			auto animator = make_shared<Animator>();
			player->AddComponent(animator);
			auto anim = RESOURCES->Get<Animation>(L"BirdRed_Anim");
			animator->SetAnimation(anim);
		}
		{
			player->AddComponent(make_shared<PlayerController>());
			player->AddComponent(make_shared<GravityController>());
		}
		scene->AddGameObject(player);
	}

	return scene;
}
