#pragma once
#include <GL/glew.h>
#include <vector>
#include "../../libs/glm/glm/glm.hpp"

class Buffer {
private:
	unsigned int ID;
public:
	void CreateBuffer(const int size, const std::vector<glm::vec4> data, const GLenum& type, const GLenum& usage);
	~Buffer();

	void Bind(GLenum type) const;
	void BindBase(const int& pos) const;
	void Unbind(GLenum type) const;
};