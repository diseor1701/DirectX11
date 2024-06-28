#pragma once

#define _XM_NO_INTRINSICS_

#include "Types.h"
#include "Values.h"
#include "Struct.h"

// STL
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

// WIN
#include <Windows.h>
#include <assert.h>


// Utils
#include "tinyxml2.h"
using namespace tinyxml2;

// DX
#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>
#include <DirectXMath.h>

// 프로젝트 속성 설정 : 추가 포함 디렉터리 / 추가 포함 라이브러리
#include <DirectXTex/DirectXTex.h>
#include <DirectXTex/DirectXTex.inl>
using namespace DirectX;
using namespace Microsoft::WRL;

#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")

#ifdef _DEBUG
#pragma comment(lib, "DirectXTex/DirectXTex_debug.lib")
#else
#pragma comment(lib, "DirectXTex/DirectXTex.lib")
#endif

#define CHECK(p) assert(SUCCEEDED(hr))

#define GAME	GGame
#define INPUT	GAME->GetInputManager()
#define TIME	GAME->GetTimeManager()
#define SCENE	GAME->GetSceneManager()
#define RESOURCES	GAME->GetResourceManager()
#define RENDER	GAME->GetRenderManager()
// Engine
#include "Graphics.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "InputLayout.h"
#include "Geometry.h"
#include "GeometryHelper.h"
#include "VertexData.h"
#include "ShaderBase.h"
#include "ConstantBuffer.h"
#include "Texture.h"
#include "RasterizerState.h"
#include "BlendState.h"
#include "SamplerState.h"
#include "Pipeline.h"
#include "Transform.h"