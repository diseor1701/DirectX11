#include "pch.h"
#include "BlendState.h"

BlendState::BlendState(ComPtr<ID3D11Device> device) : _device(device)
{

}

BlendState::~BlendState()
{

}

void BlendState::Create(D3D11_RENDER_TARGET_BLEND_DESC blendDesc /*= { true, D3D11_BLEND_SRC_ALPHA, D3D11_BLEND_INV_SRC_ALPHA, D3D11_BLEND_OP_ADD, D3D11_BLEND_ONE, D3D11_BLEND_ZERO, D3D11_BLEND_OP_ADD, D3D11_COLOR_WRITE_ENABLE_ALL }*/, float factor /*= 0.f*/)
{
	_blendFactor = factor;

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

	HRESULT hr = _device->CreateBlendState(&bd, _blendState.GetAddressOf());
	CHECK(hr);
}
