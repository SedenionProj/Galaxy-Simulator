#pragma once
#include <iostream>
#include <string>
#include <GL/glew.h>

class Texture {
private:
	unsigned int ID;
public:
	void createTexture();
	~Texture();

	void Bind() const;
	void Unbind() const;
};