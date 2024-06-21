#pragma once
class Shader
{
public:
	Shader(ComPtr<ID3D11Device> device);
	virtual ~Shader();
	
	virtual void Create(const wstring& path, const string& name, const string& version) abstract;

	ComPtr<ID3DBlob> GetBlob() { return _blob; }

	void LoadShaderFromFile(const wstring& path, const string& name, const string& version);
protected:
	// VS
	wstring _path;
	string _name;
	ComPtr<ID3D11Device> _device;
	ComPtr<ID3DBlob> _blob;
};

class VertexShader : public Shader
{
	using Super = Shader;
public:
	VertexShader(ComPtr<ID3D11Device> device);
	~VertexShader();

	virtual void Create(const wstring& path, const string& name, const string& version) override;

	ComPtr<ID3D11VertexShader> GetComPtr() { return _vertexShader; }
protected:
	ComPtr<ID3D11VertexShader> _vertexShader = nullptr;
};

class PixelShader : public Shader
{
	using Super = Shader;
public:
	PixelShader(ComPtr<ID3D11Device> device);
	~PixelShader();

	virtual void Create(const wstring& path, const string& name, const string& version) override;

	ComPtr<ID3D11PixelShader> GetComPtr() { return _pixelShader; }
protected:
	ComPtr<ID3D11PixelShader> _pixelShader = nullptr;
};

