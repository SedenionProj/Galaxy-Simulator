#pragma once
#include <GL/glew.h>

class VertexBuffer {
private:
	unsigned int ID;
public:
	VertexBuffer(const int size, const float data[]);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};