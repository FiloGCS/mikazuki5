//FiloGCS 2024
//I'm following  https://vulkan-tutorial.com/Introduction

//We don't need to include Vulkan, GLFW will do it
//#include <vulkan/vulkan.h> 
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h> 

#include <iostream>
#include <stdexcept>
#include <cstdlib>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:

    GLFWwindow* window;

    void initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //Otherwise it will use OpenGL by default
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //No window resizing for now
        window = glfwCreateWindow(WIDTH, HEIGHT, "Mikazuki 5", nullptr, nullptr);
    }

    void initVulkan() {

    }

    void mainLoop() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }

    void cleanup() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}