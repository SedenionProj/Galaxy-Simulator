#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Galaxy{
	class app {
	private:
		GLFWwindow* window;
	public:
		app();
		~app();

		void start();

		void init();

		void mainLoop();
	};
}