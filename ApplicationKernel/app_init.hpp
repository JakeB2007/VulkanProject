#ifndef APP_INIT_HPP

#define APP_INIT_HPP
#include "../WindowHandler/ve_window.hpp"

namespace VulkanEngine {
    class application {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
        const std::string title = "Vulkan Engine";
        void createWindow();
    private:
        VulkanWindow vulkanWindow{WIDTH, HEIGHT, title};


    };
}

#endif