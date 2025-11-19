#ifndef VE_WINDOW_H
#define VE_WINDOW_H

#include "ve_window.hpp"

#endif
#include <glm/gtx/io.hpp>

namespace VulkanEngine {
    VulkanWindow::VulkanWindow(uint16_t width, uint16_t height, std::string title)
        : WIDTH(width), HEIGHT(height), windowTitle(title)
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

        window = glfwCreateWindow(WIDTH, HEIGHT, windowTitle.c_str(), nullptr, nullptr);
    }

} //VulkanEngine
