#pragma once
#include "../libs/imGui/imgui_impl_glfw.h"
#include "../libs/imGui/imgui_impl_opengl3.h"
#include "../libs/imGui/imgui.h"
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
public:
	static glm::vec3 cameraPos;
	static glm::vec3 cameraFront;
	static glm::vec3 cameraUp;
	static bool firstMouse;
	static float lastX, lastY;
	static float yaw;
	static float pitch;

	GLFWwindow* window;
	GLsizei width, height;
	
public:
	app();
	~app();

	void start();

	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

	virtual void init(){}

	virtual void mainLoop(float &dt){}
};
