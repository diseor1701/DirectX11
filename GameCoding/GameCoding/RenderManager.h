#pragma once
#include "RenderHelper.h"

class RenderManager
{
public:
	RenderManager(ComPtr<ID3D11Device> device, ComPtr<ID3D11DeviceContext> deviceContext);
	
	void Init();
	void Update(shared_ptr<Graphics> graphics);

private:
	void PushCameraData();
	void PushTransformData();
	void PushAnimationData();

	// 렌더 가능한 오브젝트를 긁어오는 함수
	void GatherRenderableObjects();
	// 그 오브젝트를 그려주는 함수
	void RenderObjects();

private:
	ComPtr<ID3D11Device> _device;
	ComPtr<ID3D11DeviceContext> _deviceContext;
	shared_ptr<Pipeline> _pipeline;

private:
	// Camera
	CameraData _cameraData;
	shared_ptr<ConstantBuffer<CameraData>> _cameraBuffer;

	// SRT
	TransformData _transformData;
	shared_ptr<ConstantBuffer<TransformData>> _transformBuffer;

	// Animation
	AnimationData _animationData;
	shared_ptr<ConstantBuffer<AnimationData>> _animationBuffer;

private:
	shared_ptr<RasterizerState> _rasterizerState;
	shared_ptr<SamplerState> _samplerState;
	shared_ptr<BlendState> _blendState;

private:
	// 물체 중에서 내가 그려야할 물체들을 여기 갖고옴
	vector<shared_ptr<GameObject>> _renderObjects;
};

