#pragma once
#include <GL/glew.h>
#include "VertexBuffer.h"

class VertexArray {
public:
	unsigned int ID;
	unsigned int pos;
public:
	void createVertexArray();
	~VertexArray();
	void AddBuffer(const VertexBuffer& vb, int size, int stride, int offset);
	void Bind()const;
	void Unbind()const;
};