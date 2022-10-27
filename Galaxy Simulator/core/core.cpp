#include "core.h"

app::app()
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

app::~app()
{
    glfwTerminate();
    
}

void app::start()
{

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        mainLoop();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
}
