#pragma once
#include <GL/glew.h>
#include <vector>
#include "glm/glm.hpp"

class Buffer {
private:
	unsigned int ID;
public:
	void CreateBuffer(const GLuint size, const std::vector<glm::vec4> data, const GLenum& type, const GLenum& usage);
	~Buffer();

	void Bind(GLenum type) const;
	void BindBase(const GLuint pos) const;
	void Unbind(GLenum type) const;
};