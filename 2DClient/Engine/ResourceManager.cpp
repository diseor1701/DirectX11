#include "pch.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Shader.h"
#include "Mesh.h"
#include "Animation.h"

void ResourceManager::Init()
{
	CreateDefaultMesh();
	CreateDefaultTexture();
	CreateDefaultAnimation();
}

void ResourceManager::CreateDefaultMesh()
{
	{
		shared_ptr<Mesh> mesh = make_shared<Mesh>();
		mesh->CreateQuad();
		Add(L"Quad", mesh);
	}
	{
		shared_ptr<Mesh> mesh = make_shared<Mesh>();
		mesh->CreateCube();
		Add(L"Cube", mesh);
	}
	{
		shared_ptr<Mesh> mesh = make_shared<Mesh>();
		mesh->CreateSphere();
		Add(L"Sphere", mesh);
	}
}

void ResourceManager::CreateDefaultTexture()
{
	{
		auto texture = make_shared<Texture>();
		texture->SetName(L"Bird_Red_01-Sheet");
		texture = RESOURCES->Load<Texture>(L"Bird_Red_01-Sheet", L"..\\Resources\\Textures\\Bird_Red_01-Sheet.png");
		Add(texture->GetName(), texture);
	}
}

void ResourceManager::CreateDefaultAnimation()
{
	shared_ptr<Animation> animation = make_shared<Animation>();
	animation->SetName(L"BirdRed_Anim");
	animation->SetTexture(Get<Texture>(L"Bird_Red_01-Sheet"));
	animation->SetLoop(true);

	animation->AddKeyframe(Keyframe{ Vec2{0.f, 0.f}, Vec2{15.f, 11.f}, 0.1f });
	animation->AddKeyframe(Keyframe{ Vec2{16.f, 0.f}, Vec2{16.f, 11.f}, 0.1f });
	animation->AddKeyframe(Keyframe{ Vec2{33.f, 0.f}, Vec2{17.f, 11.f}, 0.1f });

	Add(animation->GetName(), animation);
}
