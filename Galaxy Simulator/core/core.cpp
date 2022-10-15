#include "core.h"

Galaxy::app::app()
{
    if (!glfwInit())
        std::cout << "error\n";

    window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "error\n";
    }
}

Galaxy::app::~app()
{
    glfwTerminate();
}

void Galaxy::app::start()
{

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    
}

void Galaxy::app::init()
{

}

void Galaxy::app::mainLoop()
{
}
