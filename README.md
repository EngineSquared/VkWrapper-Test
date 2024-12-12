# VkWrapper-Test

This is a test project for the VkWrapper library.

## How to use

1. Clone the repository
2. `git submodule update --init --recursive`
3. `xmake build -y`
4. `xmake run VkWrapper-Test`

## Example output

![Example Output](images/capture_app.png)

```sh
$ VkWrapper-Test>xmake run VkWrapper-Test
[2024-12-12 08:33:07.645] [info] VkWrapper config:
VKWRAPPER_VERSION=0.0.0.0
VKWRAPPER_SYSTEM=Windows
VKWRAPPER_COMPILER=MSVC
VKWRAPPER_DEBUG=Release

[2024-12-12 08:33:07.654] [info] available extensions (15): VK_KHR_device_group_creation                                                                                           VK_KHR_external_fence_capabilities       VK_KHR_external_memory_capabilities                                                                                                        VK_KHR_external_semaphore_capabilities   VK_KHR_get_physical_device_properties2                                                                                                     VK_KHR_get_surface_capabilities2 VK_KHR_surface  VK_KHR_surface_protected_capabilities                                                                                              VK_KHR_win32_surface     VK_EXT_debug_report     VK_EXT_debug_utils                                                                                                                 VK_EXT_swapchain_colorspace      VK_NV_external_memory_capabilities                                                                                                                 VK_KHR_portability_enumeration   VK_LUNARG_direct_driver_loading
```
