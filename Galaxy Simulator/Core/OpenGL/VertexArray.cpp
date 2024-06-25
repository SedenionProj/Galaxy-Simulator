#include "VertexArray.h"
#include <iostream>
#include "glm/glm.hpp"

void VertexArray::createVertexArray() {
	pos = 0;
	glGenVertexArrays(1, &ID);
}
VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &ID);
}
void VertexArray::AddBuffer(const Buffer& vb, const GLuint position, const GLenum& type, const GLuint size, const GLuint stride, const GLuint offset) {
	Bind();
	vb.Bind(type);
	glVertexAttribPointer(position, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
	glEnableVertexAttribArray(position);
}
void VertexArray::Bind() const{
	glBindVertexArray(ID);
}
void VertexArray::Unbind() const{
	glBindVertexArray(0);

}