#pragma once
#include <GL/glew.h>
#include "Buffer.h"

class VertexArray {
public:
	void createVertexArray();
	~VertexArray();
	void AddBuffer(const Buffer& vb, const GLuint position, const GLenum& type, const GLuint size, const GLuint stride, const GLuint offset);
	void Bind()const;
	void Unbind()const;
private:
	unsigned int ID;
	unsigned int pos;
};