#ifndef VE_WINDOW_HPP
#define VE_WINDOW_HPP

#define GLFW_INCLUDE_VULKAN
#include <string>
#include "../lib/glfw-3.4/include/GLFW/glfw3.h"


#endif

namespace VulkanEngine {
    class VulkanWindow {
    public:
        VulkanWindow(uint16_t width, uint16_t height, std::string title);
        ~VulkanWindow();

    private:
        void initWindow();

        const uint16_t WIDTH;
        const uint16_t HEIGHT;

        std::string windowTitle = "Application Window";

        GLFWwindow* window{};

    };
}