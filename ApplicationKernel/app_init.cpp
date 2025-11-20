#include "app_init.hpp"

namespace VulkanEngine {
    void application::createWindow() {
        while (vulkanWindow.shouldClose()) {
            glfwPollEvents();
        }
    }

}


