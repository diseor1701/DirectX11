#pragma once
#include "IExecute.h"
#include "Geometry.h"

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
	shared_ptr<Texture> _playerTexture;

public:
	ComPtr<ID3D11BlendState> m_pAlphaBlend = nullptr;
};

