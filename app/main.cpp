/*
** EPITECH PROJECT, 2024
** EngineSquared
** File description:
** main
*/

#include "VkWrapper.hpp"
#include "Window.hpp"

using namespace ES::Plugin;

int main()
{
    Window::Resource::Window window(800, 600, "VkWrapper Test");
    VkWrapper vkWrapper;

    vkWrapper.CreateInstance(window.GetGLFWWindow(), "VkWrapper Test", 800, 600);

    vkWrapper.AddTexture("/home/laplace/VkWrapper-Test/assets/images/texture.png");

    vkWrapper.AddShader(SHADER_DIR "vert.spv", "main", VkWrapper::ShaderType::VERTEX);
    vkWrapper.AddShader(SHADER_DIR "frag.spv", "main", VkWrapper::ShaderType::FRAGMENT);

    vkWrapper.CreatePipeline();

    window.SetFramebufferSizeCallback((void *) &vkWrapper, VkWrapper::ResizeCallback);

    VkWrapper::PrintConfig();
    VkWrapper::PrintAvailableExtensions();

    try
    {
        while (!window.ShouldClose())
        {
            glfwPollEvents();

            if (vkWrapper.DrawFrame() == Wrapper::Result::NeedResize)
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
