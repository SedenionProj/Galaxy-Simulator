#pragma once

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "OpenGL/Shader.h"
#include "OpenGL/VertexArray.h"
#include "OpenGL/Buffer.h"
#include "OpenGL/Renderer.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui.h"



class WindowApp {

public:
	WindowApp(GLuint width, GLuint height);
	~WindowApp();

	void start();
	virtual void init() = 0;
	virtual void mainLoop(float dt) = 0;
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

protected:
	static glm::vec3 cameraPos;
	static glm::vec3 cameraFront;
	static glm::vec3 cameraUp;
	static bool firstMouse;
	static float lastX, lastY;
	static float yaw;
	static float pitch;
	static bool staticCam;

protected:
	GLFWwindow* window;
	GLsizei width, height;
};
