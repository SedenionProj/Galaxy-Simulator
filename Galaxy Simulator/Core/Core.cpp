#include "core.h"

glm::vec3 WindowApp::cameraPos = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 WindowApp::cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 WindowApp::cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

bool  WindowApp::firstMouse = true;
float WindowApp::lastX = 1280 / 2, WindowApp::lastY = 1280 / 2;
float WindowApp::yaw = 0.0f;
float WindowApp::pitch = 0.0f;
bool  WindowApp::staticCam = false;

WindowApp::WindowApp(GLuint width, GLuint height): width(width), height(height) {
    // crée la fenêtre
    if (!glfwInit()) {
        std::cout << "error initializing glfw\n";
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    window = glfwCreateWindow(width, height, "Galaxy", glfwGetPrimaryMonitor(), NULL);

    if (!window) {
        std::cout << "error initializing glfw window\n";
        return;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "error initializing glew\n";
        return;
    }

    glViewport(0, 0, width, height);
   
    glfwSetCursorPosCallback(window, mouse_callback);
    
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void WindowApp::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    // change la rotation de la camera en fonction de position de la souris
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;
    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    yaw += xoffset;
    pitch += yoffset;
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    if(!WindowApp::staticCam)
        cameraFront = glm::normalize(direction);
}

WindowApp::~WindowApp() {
    // termine/éteint le programe
    Renderer::Terminate();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}


void WindowApp::start() {
    // fait commencer le programme
    init();
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    double prevTime = 0.0;
    double timeDiff;
    float currentFrame = glfwGetTime();

    Renderer::Init(window);

    while (!glfwWindowShouldClose(window)) {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        timeDiff = currentFrame - prevTime;
        lastFrame = currentFrame;

        Renderer::GuiFrame();
        Renderer::Clear();

        mainLoop(deltaTime);

        Renderer::GuiRender();
        Renderer::Display(window);
    }
}
