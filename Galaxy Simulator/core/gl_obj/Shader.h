#pragma once
#include <iostream>
#include <GL/glew.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "../../libs/glm/glm/glm.hpp"

class Shader {
private:
	unsigned int ID;
public:
	void createShader(const char* vertexPath, const char* fragmentPath);
	~Shader();
	void Bind() const;
	void Unind() const;
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVec3(const std::string& name, float v1, float v2, float v3) const;
	void setMat4(const std::string& name, const glm::mat4& matrix) const;
private:
	const char* readFile(const char* path);
};