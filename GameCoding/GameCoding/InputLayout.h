#pragma once
class InputLayout
{
public:
	InputLayout(ComPtr<ID3D11Device> device);
	~InputLayout();

	ComPtr<ID3D11InputLayout> GetComPtr() { return _inputLayout; }

	void Create(const vector<D3D11_INPUT_ELEMENT_DESC>& descs, ComPtr<ID3DBlob> blob);
private:
	ComPtr<ID3D11Device> _device;

	ComPtr<ID3D11InputLayout> _inputLayout = nullptr;
	// 인덱스 버퍼는 삼각형의 개수를 넘겨주는 그 정점의 개수를 줄 일 수있다.
	// 메모리 쪽으로 항상 효율적으로 작업할 수 있다. (다 넘기지 않고 일부만 넘기기 가능)
};

