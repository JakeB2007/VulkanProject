cmake_minimum_required(VERSION 3.16)
project(VulkanProject)

set(CMAKE_CXX_STANDARD 20)

set(VULKAN_SDK $ENV{VULKAN_SDK})

if(NOT VULKAN_SDK)
    message(FATAL_ERROR "VULKAN_SDK environment variable not set!")
endif ()

include_directories(${VULKAN_SDK}/Include)
link_directories(${VULKAN_SDK}/Lib)

add_library(Vulkan INTERFACE
        WindowHandler/ve_window.hpp)
target_include_directories(Vulkan INTERFACE ${VULKAN_SDK}/Include)

if(WIN32)
    target_link_libraries(Vulkan INTERFACE ${VULKAN_SDK}/Lib/vulkan-1.lib)
elseif (APPLE)
    target_link_libraries(Vulkan INTERFACE ${VULKAN_SDK}/lib/libMoltenVK.dylib)
endif ()

add_subdirectory(lib/glfw-3.4)

add_subdirectory(lib/g-truc-glm-a532f5b EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME}
        main.cpp
        WindowHandler/ve_window.hpp
        WindowHandler/ve_window.cpp
        ApplicationKernel/app_init.hpp
)

target_link_libraries(${PROJECT_NAME} Vulkan glfw glm)

if(APPLE)
    message(STATUS "Configuring for macOS with MoltenVK + Cocoa frameworks")
    target_link_libraries(${PROJECT_NAME}
            "-framework Cocoa"
            "-framework IOKit"
            "-framework CoreFoundation"
    )
endif ()

if(WIN32)
    add_definitions(-DVK_USE_PLATFORM_WIN32_KHR)
endif ()


