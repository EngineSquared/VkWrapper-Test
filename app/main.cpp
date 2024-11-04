/*
** EPITECH PROJECT, 2024
** EngineSquared
** File description:
** main
*/

#include "VkWrapper.hpp"
#include "Window.hpp"

#include <iostream>

int main()
{
    ES::Plugin::Window::Resource::Window window(800, 600, "VkWrapper Test");
    ES::Plugin::VkWrapper vkWrapper;
    ES::Plugin::VkWrapper::CreateInfo createInfo = {
        .window = window.GetGLFWWindow(),
        .width = 800,
        .height = 600,
        .applicationName = "VkWrapper Test",
        .shaders = {{SHADER_DIR "vert.spv", "main"}, {SHADER_DIR "frag.spv", "main"}}
    };

    vkWrapper.Create(createInfo);
    window.SetFramebufferSizeCallback((void *) &vkWrapper, ES::Plugin::VkWrapper::ResizeCallback);

    vkWrapper.PrintConfig();
    vkWrapper.PrintAvailableExtensions();

    try
    {
        while (!window.ShouldClose())
        {
            glfwPollEvents();

            if (vkWrapper.DrawFrame() == ES::Plugin::Wrapper::Result::Failure)
                vkWrapper.Resize(window.GetGLFWWindow());
        }

        vkWrapper.Destroy();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
