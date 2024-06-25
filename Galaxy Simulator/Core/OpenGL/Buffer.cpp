#include "Buffer.h"


void Buffer::CreateBuffer(const GLuint size, const std::vector<glm::vec4> data, const GLenum &type, const GLenum &usage)
{
	glGenBuffers(1, &ID);
	glBindBuffer(type, ID);
	glBufferData(type, size, &data[0], usage);
}
Buffer::~Buffer() {
	glDeleteBuffers(1,&ID);
}

void Buffer::Bind(GLenum type) const {
	glBindBuffer(type, ID);
}
void Buffer::BindBase(const GLuint pos) const
{
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, pos, ID);
}
void Buffer::Unbind(GLenum type) const {
	glBindBuffer(type, 0);
}
