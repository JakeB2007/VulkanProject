#ifndef VE_WINDOW_HPP
#define VE_WINDOW_HPP

#define GLFW_INCLUDE_VULKAN
#include <string>
#include "../lib/glfw-3.4/include/GLFW/glfw3.h"

namespace VulkanEngine {
    class VulkanWindow {
    public:
        VulkanWindow(int w, int h, std::string t);
        ~VulkanWindow();
        bool shouldClose();

    private:
        void initWindow();

        const int width;
        const int height;

        std::string windowTitle;

        GLFWwindow* window{};

    };
}

#endif