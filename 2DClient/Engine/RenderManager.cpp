#include "pch.h"
#include "RenderManager.h"
#include "MeshRenderer.h"
#include "Camera.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Mesh.h"
#include "Animator.h"

void RenderManager::Init(shared_ptr<Shader> shader)
{
	_shader = shader;

	_animationBuffer = make_shared<ConstantBuffer<AnimationData>>();
	_animationBuffer->Create();
	_animationEffectBuffer = _shader->GetConstantBuffer("AnimationBuffer");
}

void RenderManager::Update()
{
	GatherRenderableObjects();
	RenderObjects();
}

void RenderManager::PushAnimationData(const AnimationData& desc)
{
	_animationData = desc;
	_animationBuffer->CopyData(_animationData);
}

void RenderManager::GatherRenderableObjects()
{
	_renderObjects.clear();

	auto& gameObjects = SCENE->GetCurrentScene()->GetGameObjects();
	for (const shared_ptr<GameObject>& gameObject : gameObjects)
	{
		shared_ptr<MeshRenderer> meshRenderer = gameObject->GetMeshRenderer();
		if (meshRenderer)
			_renderObjects.push_back(gameObject);
	}
}

void RenderManager::RenderObjects()
{
	for (const shared_ptr<GameObject>& gameObject : _renderObjects)
	{
		shared_ptr<MeshRenderer> meshRenderer = gameObject->GetMeshRenderer();
		if (meshRenderer == nullptr)
			continue;

		shared_ptr<Transform> transform = gameObject->GetTransform();
		if (transform == nullptr)
			continue;

		// Animation
		shared_ptr<Animator> animator = gameObject->GetAnimator();
		if (animator)
		{
			const Keyframe& keyframe = animator->GetCurrentKeyframe();
			_animationData.spriteOffset = keyframe.offset;
			_animationData.spriteSize = keyframe.size;
			_animationData.textureSize = animator->GetCurrentAnimation()->GetTextureSize();
			_animationData.useAnimation = 1.0f;
			PushAnimationData(_animationData);

			_animationEffectBuffer->SetConstantBuffer(_animationBuffer->GetComPtr().Get());
			meshRenderer->SetTexture(animator->GetCurrentAnimation()->GetTexture());
		}
		else
		{
			_animationData.spriteOffset = Vec2(0.f, 0.f);
			_animationData.spriteSize = Vec2(0.f, 0.f);
			_animationData.textureSize = Vec2(0.f, 0.f);
			_animationData.useAnimation = 0.f;
			PushAnimationData(_animationData);

			_animationEffectBuffer->SetConstantBuffer(_animationBuffer->GetComPtr().Get());
			meshRenderer->SetTexture(meshRenderer->GetTexture());
		}
		meshRenderer->Update();
	}
}
