/*
** EPITECH PROJECT, 2024
** EngineSquared
** File description:
** main
*/

#include "Vk-Wrapper.hpp"
#include "WindowSystem.hpp"

using namespace ES::Plugin;

int main()
{
    ES::Engine::Core core;

    core.RegisterSystem<ES::Engine::Scheduler::Startup>(Window::System::CreateWindow);
    core.RegisterSystem<ES::Engine::Scheduler::Startup>(Window::System::EnableVSync);

    core.RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::InitVkWrapper);
    core.RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::AddTextureAndModel);
    core.RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::AddShaders);
    core.RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::CreatePipeline);
    core.RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::ChangeClearColor);
    core.RegisterSystem<ES::Engine::Scheduler::Startup>(Wrapper::System::DisplayConfigs);

    core.RunSystems();

    core.RegisterSystem<ES::Engine::Scheduler::Update>(Window::System::PollEvents);
    core.RegisterSystem<ES::Engine::Scheduler::Update>(Window::System::UpdateKey);
    core.RegisterSystem<ES::Engine::Scheduler::Update>(Wrapper::System::DrawFrame);

    while (!core.GetResource<ES::Plugin::Window::Resource::Window>().ShouldClose()) {
        core.RunSystems();
    }

    core.GetResource<ES::Plugin::VkWrapper>().Destroy();

    return 0;
}
