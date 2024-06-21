#pragma once

// template 클래스 들어가면 cpp에 구현부 넣으면 안됨
template<typename T>
class Geometry
{
public:
	Geometry() {}
	~Geometry() {}

	uint32 GetVertexCount() { return static_cast<int>(_vertices.size()); }
	void* GetVertexData() { return _vertices.data(); }
	const vector<T>& GetVertices() { return _vertices; }

	uint32 GetIndexCount() { return static_cast<uint32>(_indices.size()); }
	void* GetIndexData() { return _indices.data(); }
	const vector<uint32>& GetIndices() { return _indices; }

	void AddVertex(const T& vertex) { _vertices.push_back(vertex); }
	void AddVertices(const vector<T>& vertices) { _vertices.insert(_vertices.end(), vertices.begin(), vertices.end()); }
	void SetVertices(const vector<T>& vertices) { _vertices = vertices; }

	void AddIndex(const T& Index) { _indices.push_back(Index); }
	void AddIndices(const vector<uint32>& indices) { _indices.insert(_indices.end(), indices.begin(), indices.end()); }
	void SetIndices(const vector<uint32>& indices) { _indices = indices; }
private:
	// Geometry (mesh)
	vector<T> _vertices;
	vector<uint32> _indices;
};

