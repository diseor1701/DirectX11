#include "pch.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "Animation.h"

ResourceManager::ResourceManager(ComPtr<ID3D11Device> device)
	: _device(device)
{

}

void ResourceManager::Init()
{
	CreateDefaultTexture();
	CreateDefaultMesh();
	CreateDefaultShader();
	CreateDefaultMaterial();
	CreateDefaultAnimation();
}

void ResourceManager::CreateDefaultTexture()
{
	// Map
	{
		auto texture = make_shared<Texture>(_device);
		texture->SetName(L"Map");
		texture->Create(L"..\\Resources\\Textures\\BG_01.png");
		Add(texture->GetName(), texture);
	}
	// Floor
	{
		auto texture = make_shared<Texture>(_device);
		texture->SetName(L"Floor");
		texture->Create(L"..\\Resources\\Textures\\Floor2.png");
		Add(texture->GetName(), texture);
	}
	// Player
	{
		auto texture = make_shared<Texture>(_device);
		texture->SetName(L"Bird_Red_01");
		texture->Create(L"..\\Resources\\Textures\\Bird_Red_01-Sheet.png");
		Add(texture->GetName(), texture);
	}
}

void ResourceManager::CreateDefaultMesh()
{
	// Map
	{
		shared_ptr<Mesh> mesh = make_shared<Mesh>(_device);
		mesh->SetName(L"Map");
		mesh->CreateMap(450, 800);
		Add(mesh->GetName(), mesh);
	}
	// Floor
	{
		shared_ptr<Mesh> mesh = make_shared<Mesh>(_device);
		mesh->SetName(L"Floor");
		mesh->CreateMap(900, 150);
		Add(mesh->GetName(), mesh);
	}

	// Rectangle
	{
		shared_ptr<Mesh> mesh = make_shared<Mesh>(_device);
		mesh->SetName(L"Rectangle");
		mesh->CreateDefautRectangle();
		Add(mesh->GetName(), mesh);
	}
}

void ResourceManager::CreateDefaultShader()
{
	auto vertexShader = make_shared<VertexShader>(_device);
	vertexShader->Create(L"Default.hlsl", "VS", "vs_5_0");
	auto inputLayout = make_shared<InputLayout>(_device);
	inputLayout->Create(VertexTextureData::descs, vertexShader->GetBlob());
	auto pixelShader = make_shared<PixelShader>(_device);
	pixelShader->Create(L"Default.hlsl", "PS", "ps_5_0");

	// Shader
	shared_ptr<Shader> shader = make_shared<Shader>();
	shader->SetName(L"Default");
	shader->_vertexShader = vertexShader;
	shader->_inputLayout = inputLayout;
	shader->_pixelShader = pixelShader;
	Add(shader->GetName(), shader);
}

void ResourceManager::CreateDefaultMaterial()
{
	// Map
	{
		shared_ptr<Material> material = make_shared<Material>();
		material->SetName(L"Map");
		material->SetShader(Get<Shader>(L"Default"));
		material->SetTexture(Get<Texture>(L"Map"));
		Add(material->GetName(), material);
	}
	// Floor
	{
		shared_ptr<Material> material = make_shared<Material>();
		material->SetName(L"Floor");
		material->SetShader(Get<Shader>(L"Default"));
		material->SetTexture(Get<Texture>(L"Floor"));
		Add(material->GetName(), material);
	}
	// Player
	{
		shared_ptr<Material> material = make_shared<Material>();
		material->SetName(L"Player");
		material->SetShader(Get<Shader>(L"Default"));
		material->SetTexture(Get<Texture>(L"Bird_Red_01"));
		Add(material->GetName(), material);
	}
}

void ResourceManager::CreateDefaultAnimation()
{
	shared_ptr<Animation> animation = make_shared<Animation>();
	animation->SetName(L"BirdRed_Anim");
	animation->SetTexture(Get<Texture>(L"Bird_Red_01"));
	animation->SetLoop(true);

	animation->AddKeyframe(Keyframe{ Vec2{0.f, 0.f}, Vec2{15.f, 11.f}, 0.1f });
	animation->AddKeyframe(Keyframe{ Vec2{16.f, 0.f}, Vec2{16.f, 11.f}, 0.1f });
	animation->AddKeyframe(Keyframe{ Vec2{33.f, 0.f}, Vec2{17.f, 11.f}, 0.1f });

	Add(animation->GetName(), animation);

	// XML + JSON
	animation->Save(L"TestAnim.xml");

	shared_ptr<Animation> anim2 = make_shared<Animation>();
	anim2->Load(L"TestAnim.xml");
}
