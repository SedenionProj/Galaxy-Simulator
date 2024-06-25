#pragma once
#include "VertexArray.h"
#include "Shader.h"
#include <GLFW/glfw3.h>

class Renderer {
public:
	static void Init(GLFWwindow* window);
	static void Terminate();

	static void DrawArray(const VertexArray& va, const Shader& shader, const GLsizei size);
	static void Clear();
	
	static void GuiFrame();
	static void GuiRender();

	static void Display(GLFWwindow* window);
};