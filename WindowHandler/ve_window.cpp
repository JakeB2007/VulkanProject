#include "ve_window.hpp"
#include <glm/gtx/io.hpp>

namespace VulkanEngine {
    VulkanWindow::VulkanWindow(int w, int h, std::string t)
        : width(w), height(h), windowTitle(t)
    {
        initWindow();
    }

    VulkanWindow::~VulkanWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }


    void VulkanWindow::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowTitle.c_str(), nullptr, nullptr);
    }

    bool VulkanWindow::shouldClose() {
        return glfwWindowShouldClose(window);
    }

} //VulkanEngine
