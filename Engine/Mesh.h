#pragma once

// 정점으로 이루어진 물체
// 즉 정점의 모임
class Mesh
{
public:
	void Init(vector<Vertex>& vec);
	void Render();

	void SetTransform(const Transform& t) { _transform = t; }
private:
	ComPtr<ID3D12Resource> _vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW _vertexBufferView = {};
	uint32 _vertexCount = 0;

	Transform _transform = {};
};

