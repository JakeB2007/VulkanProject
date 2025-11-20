#include <exception>
#include <iostream>
#include <ostream>
#include <cstdlib>

#include "ApplicationKernel/app_init.hpp"
#include <iostream>

int main() {
    VulkanEngine::application app;

    try {
        app.createWindow();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
