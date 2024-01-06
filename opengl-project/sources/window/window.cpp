#include <iostream>
#include <glad/glad.h>

#include <window/window.h>

std::optional<GLFWwindow*> window::initialize_window(const int width, const int height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "Hi", NULL, NULL);
    if (window == nullptr) {
        std::cout << "No window" << std::endl;
        glfwTerminate();
        return std::nullopt;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "No GLAD" << std::endl;
        return std::nullopt;
    }
    glViewport(0, 0, width, height);

    return window;
}
