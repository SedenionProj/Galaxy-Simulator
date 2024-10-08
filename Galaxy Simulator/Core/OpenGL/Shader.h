#pragma once
#include <iostream>
#include <string>

#include "glm/glm.hpp"
#include "Buffer.h"

class Shader {
private:
	unsigned int ID;
public:
	void createVFShader(const char* vertexPath, const char* fragmentPath);
	void createCShader(const char* vertexPath);
	~Shader();
	void useCompute(const Buffer& ssbo, const GLsizei size);
	void Bind() const;
	void Unind() const;
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec3(const std::string& name, float v1, float v2, float v3) const;
	void setMat4(const std::string& name, const glm::mat4& matrix) const;
};