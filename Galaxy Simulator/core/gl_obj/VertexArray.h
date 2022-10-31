#pragma once
#include <GL/glew.h>
#include "Buffer.h"

class VertexArray {
public:
	unsigned int ID;
	unsigned int pos;
public:
	void createVertexArray();
	~VertexArray();
	void AddBuffer(const Buffer& vb, const GLint& position, const  GLenum& type, int size, int stride, int offset);
	void Bind()const;
	void Unbind()const;
};