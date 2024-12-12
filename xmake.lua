add_requires("entt", "vulkan-headers", "vulkansdk", "vulkan-hpp", "glfw", "glm", "gtest", "raylib", "spdlog")
add_requires("raylib")

set_project("VkWrapper-Test")
set_languages("c++20")

includes("ThirdParty/EngineSquared/xmake.lua")

target("VkWrapper-Test")
    set_kind("binary")

    add_files("app/main.cpp")

    add_deps("EngineSquared")

    add_packages("entt", "vulkansdk", "glfw", "glm", "spdlog")

if is_mode("debug") then
    add_defines("DEBUG")
    set_symbols("debug")
    set_optimize("none")
    if is_plat("windows") then
        add_cxflags("/Od", "/Zi")
    else
        add_cxflags("-O0 -g3 -ggdb")
    end
end

if is_mode("release") then
    add_defines("NDEBUG")
    set_optimize("fastest")
end

target("shader")
    set_kind("phony")
    add_deps("EngineSquared")
    on_build(function(target)
        import("core.base.option")
        import("core.project.config")
        import("core.base.task")
        local buildir = path.join("$(buildir)", "$(plat)", "$(arch)", "$(mode)")
        os.mkdir(path.join(buildir, "shaders"))

        local shader_files = os.files("shaders/*.*")

        for _, shader_file in ipairs(shader_files) do
            local extension = string.sub(path.extension(shader_file), 2)
            local output_file = path.join("shaders", extension .. ".spv") -- path.filename(shader_file)

            os.execv("glslc", {shader_file, "-o", output_file})

            os.cp(output_file, path.join(buildir, "shaders"))
            os.rm(output_file)
        end
    end)
