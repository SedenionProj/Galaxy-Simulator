#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "../libs/glm/glm/glm.hpp"
#include "../libs/glm/glm/gtc/matrix_transform.hpp"
#include "../libs/glm/glm/gtc/type_ptr.hpp"
#include "gl_obj/Shader.h"
#include "gl_obj/VertexArray.h"
#include "gl_obj/Texture.h"
#include "gl_obj/Buffer.h"
#include "gl_obj/IndexBuffer.h"
#include "gl_obj/Renderer.h"

class app {
protected:
	GLFWwindow* window;
	GLsizei width, height;
public:
	app();
	~app();

	void start();

	virtual void init(){}

	virtual void mainLoop(){}
};
