#pragma once
#include "IExecute.h"
#include "Geometry.h"

class Transform;

class SamplerDemo : public IExecute
{
public:
	void Init() override;
	void Update() override;
	void Render() override;

	HRESULT SetAlphaBlendState();

	shared_ptr<Shader> _shader;

	// map
	shared_ptr<GameObject> _map;	
	// Object
	shared_ptr<GameObject> _player;
	// Camera
	shared_ptr<GameObject> _camera;

	// Player
	shared_ptr<Transform> _playerTransform;

public:
	ComPtr<ID3D11BlendState> m_pAlphaBlend = nullptr;
};

