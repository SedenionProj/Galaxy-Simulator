#include "core.h"

glm::vec3 app::cameraPos = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 app::cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 app::cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
bool app::firstMouse = true;
float app::lastX = 1280 / 2, app::lastY = 1280 / 2;
float app::yaw = 0.0f;
float app::pitch = 0.0f;

app::app(): width(1920), height(1080)
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
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);

    
}

void app::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse)
    {
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
    cameraFront = glm::normalize(direction);
}

app::~app()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}


void app::start()
{

    init();
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    double prevTime = 0.0;
    double timeDiff;
    unsigned int counter = 0;
    float currentFrame = glfwGetTime();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        timeDiff = currentFrame - prevTime;
        lastFrame = currentFrame;
        counter++;

        mainLoop(deltaTime);

        ImGui::EndFrame();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
}
