
1. Setting up the main window to display our graphics - done by using GLFW(Graphics Library Framewrok) to interact with the graphics API. Replaced 
    #include<vulkan/vulkan.h>
By 
	#define GLFW_INCLUDE_VULKAN
	#include <GLFW/glfw3.h>
2. Setup a vulkan instance by setting up a data member of type VkInstance, initializing the vulkan library and allowing the application to pass its information to vulkan.
3. Use VkApplicationInfo struct to provide application information to the instance. Define **sType**: structure Type, **pApplicationName**: name of the vulkan application, **applicationVersion**: Define application version using **VK_MAKE_VERSION()** function, **pEngineName**: Define engine name of application, **engineVersion**: define engine version **again using VK_MAKE_VERSION()**, **apiVersion**: set to **VK_API_VERSION_1_0** in this case.
**NOTE**
	A Lot of information in vulkan is passed using structs instead of function parameters. And usually we need to fill in more than one struct to provide the nexessary information for creating an instance.

**SHADERS** - Creating a Graphics Pipeline
    Written in GLSL, language to write shaders.
	1. *Vertex shaders*
	2. *Fragment Shaders*
	Compile shaders using glsl, read the compile .spv file and load its contents to create a graphics pipeline.