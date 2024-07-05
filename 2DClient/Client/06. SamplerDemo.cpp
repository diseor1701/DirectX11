#include "pch.h"
#include "06. SamplerDemo.h"
#include "GeometryHelper.h"
#include "Camera.h"
#include "GameObject.h"
#include "CameraScript.h"
#include "PlayerController.h"
#include "MeshRenderer.h"
#include "Mesh.h"
#include "Animation.h"
#include "Animator.h"


HRESULT  SamplerDemo::SetAlphaBlendState()
{
	HRESULT hr;
	D3D11_BLEND_DESC bd;
	ZeroMemory(&bd, sizeof(D3D11_BLEND_DESC));

	bd.AlphaToCoverageEnable = FALSE;//discard;���� ���.
	bd.IndependentBlendEnable = FALSE;
	//D3D11_RENDER_TARGET_BLEND_DESC RenderTarget[8];
	// ������� �÷���(DestBlend) ��  ���� ��� �÷�(SrcBlend)���� ȥ�տ����Ѵ�.
	bd.RenderTarget[0].BlendEnable = TRUE;
	// RGA �÷��� ����( �⺻ ���ĺ��� ����) ���Ĺ���( 0 ~ 1 )
	// ���� �÷��� = �ҽ��÷�*�ҽ����� 	+  ����ũ�÷�* (1.0 - �ҽ�����)
	//  ������ġ = ��������ġ*S + ������ġ* (1- S); S=0, S=0.5, S = 1
	// 
	// ���� �ҽ��÷� = 1,0,0,1(����)   ����÷� = 0,0,1,1(�Ķ�)
	// 1)�ҽ����� = 1.0F ( ����������)
		// RGB = R*ALPHA, G = G*Alpha, B = B*Alpha
		// ���� �÷��� = ����*1.0F 	+  �Ķ�* (1.0 - 1.0F)
		// ->���� �÷���(�ҽ���) = [1,0,0] 	+  [0,0,0]
	// 2)�ҽ����� = 0.0F ( ��������)
		// RGB = R*ALPHA, G = G*Alpha, B = B*Alpha
		// ���� �÷��� = ����*0.0F 	+  �Ķ�* (1.0 - 0.0F)
		// ->���� �÷���(����) = [0,0,0] +  [0,0,1]
	bd.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	bd.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	bd.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	// A ���İ� ����
	// A = SRC Alpha*1 + DestAlpha*0;
	bd.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	bd.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	bd.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

	bd.RenderTarget[0].RenderTargetWriteMask =
		D3D11_COLOR_WRITE_ENABLE_ALL;

	hr = DEVICE->CreateBlendState(&bd, m_pAlphaBlend.GetAddressOf());
	if (SUCCEEDED(hr))
	{
		DC->OMSetBlendState(m_pAlphaBlend.Get(), 0, -1);
	}
	return hr;
}

void SamplerDemo::Init()
{
	SetAlphaBlendState();

	RESOURCES->Init();
	auto shader = make_shared<Shader>(L"05. Sampler.fx");

	// Camera
	_camera = make_shared<GameObject>();
	_camera->GetOrAddTransform()->SetPosition(Vec3(0.f, 0.f, -10.f));
	_camera->AddComponent(make_shared<Camera>());
	shared_ptr<CameraScript> cs = make_shared<CameraScript>();

	// Map
	_map = make_shared<GameObject>();
	_map->GetOrAddTransform()->SetPosition(Vec3(0.f, 0.f, 0.f));
	_map->AddComponent(make_shared<MeshRenderer>());
	_map->GetMeshRenderer()->SetShader(shader);
	shared_ptr<Mesh> map_mesh = make_shared<Mesh>();
	map_mesh->CreateMap(144, 256);
	RESOURCES->Add(L"Map", map_mesh);
	_map->GetMeshRenderer()->SetMesh(map_mesh);
	auto map = RESOURCES->Load<Texture>(L"BG_01.png", L"..\\Resources\\Textures\\BG_01.png");
	_map->GetMeshRenderer()->SetTexture(map);

	CUR_SCENE->Add(_map);

	// Player
	_player = make_shared<GameObject>();
	_playerTransform = _player->GetOrAddTransform();
	_playerTransform->SetLocalScale(Vec3(20.2f, 14.2f, 0.f));
	_playerTransform->SetPosition(Vec3(72.f, 100.f, -1.f));
	_player->AddComponent(make_shared<MeshRenderer>());
	{
		{
			_player->GetMeshRenderer()->SetShader(shader);
		}
		{
			auto mesh2 = RESOURCES->Get<Mesh>(L"Quad");
			_player->GetMeshRenderer()->SetMesh(mesh2);
		}
		{
			auto texture2 = RESOURCES->Load<Texture>(L"Bird_Red_01", L"..\\Resources\\Textures\\Bird_Red_01.png");
			_player->GetMeshRenderer()->SetTexture(texture2);
		}
		{
			auto animator = make_shared<Animator>();
			auto anim = RESOURCES->Get<Animation>(L"BirdRed_Anim");
			animator->SetAnimation(anim);
			_player->AddComponent(animator);
		}
	}
	_player->AddComponent(make_shared<PlayerController>());

	cs->SetTarget(_player);
	_camera->AddComponent(cs);
	CUR_SCENE->Add(_camera);

	CUR_SCENE->Add(_player);

	RENDER->Init(shader);
}

void SamplerDemo::Update()
{
	_player->Update();
	_map->Update();
	_camera->LateUpdate();
}

void SamplerDemo::Render()
{
	/*_shader->GetMatrix("World")->SetMatrix((float*)&_world);
	_shader->GetMatrix("View")->SetMatrix((float*)&Camera::S_MatView);
	_shader->GetMatrix("Projection")->SetMatrix((float*)&Camera::S_MatProjection);
	_shader->GetSRV("Texture0")->SetResource(_texture->GetComPtr().Get());

	enum ADDRESS_VALUE
	{
		ADDRESS_WRAP = 0,
		ADDRESS_MIRROR = 1,
		ADDRESS_CLAMP = 2,
		ADDRESS_BORDER = 3,
	};
	
	_shader->GetScalar("Address")->SetInt(ADDRESS_WRAP);

	uint32 stride = _vertexBuffer->GetStride();
	uint32 offset = _vertexBuffer->GetOffset();

	DC->IASetVertexBuffers(0, 1, _vertexBuffer->GetComPtr().GetAddressOf(), &stride, &offset);
	DC->IASetIndexBuffer(_indexBuffer->GetComPtr().Get(), DXGI_FORMAT_R32_UINT, 0);

	_shader->DrawIndexed(0, 0, _indexBuffer->GetCount(), 0, 0);*/
}
