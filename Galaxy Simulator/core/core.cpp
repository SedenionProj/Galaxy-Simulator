#include "core.h"

app::app(): width(1280), height(720)
{

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    if (!glfwInit())
        std::cout << "error\n";

    window = glfwCreateWindow(width, height, "Galaxy", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "error\n";
    }

    glViewport(0, 0, width, height);
}

app::~app()
{
    glfwTerminate();
    
}

void app::start()
{
    init();

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        mainLoop();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
}
