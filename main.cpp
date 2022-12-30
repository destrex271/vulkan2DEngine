#include <exception>
#include <vulkan/vulkan_core.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <string.h>

class BaseShapesVulkan{
	public:
		void run(){
			initWindow();
			initVulkan();
			mainLoop();
			cleanUp();
		}
	
	private:
		
		GLFWwindow* window; // Main window
		VkInstance instance; // Main Vulkan instance

		// specifying window size parameters
		const uint32_t WIDTH = 800;
		const uint32_t HEIGHT = 600;
		const char* TITLE = "VULKAN WINDOW";

		void initWindow(){
			glfwInit(); // Initialize window of Graphics Library Framework
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Disable the call to default opengl api byglfw to replace it by vulkan later
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Diable Resize ability of window

			window = glfwCreateWindow(WIDTH, HEIGHT, TITLE,nullptr, nullptr); // monitor stands for which monitor to display window on
		}
		void initVulkan(){
			createInstance();
			checkSupportedExtensions();
		}
		void checkSupportedExtensions(){
			uint32_t usedExtensionCount = 0;
			const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&usedExtensionCount);
			std::cout << "Using extensions: " << std::endl;
			uint32_t extensionsCount = 0;
			vkEnumerateInstanceExtensionProperties(nullptr, &extensionsCount, nullptr);
			std::vector<VkExtensionProperties> extensions(extensionsCount);
			vkEnumerateInstanceExtensionProperties(nullptr, &extensionsCount, extensions.data());

			for(int i = 0; i < usedExtensionCount; i++){
				std::cout << glfwExtensions[i];
				for(int j = 0; j < extensionsCount; j++){
					if(strcmp(extensions.at(j).extensionName, glfwExtensions[i]) == 0){
						std::cout << "\t\tfrom Available";
					}
				}
				std::cout << std::endl;
			}

		}
		void createInstance(){
			VkApplicationInfo appInfo{};
			appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO; // define application structure type
			appInfo.pApplicationName = "2D Physics Engine";
			appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
			appInfo.pEngineName = "My Engine";
			appInfo.engineVersion = VK_MAKE_VERSION(1,0,0);
			appInfo.apiVersion = VK_API_VERSION_1_0;

			VkInstanceCreateInfo createInfo{};
			createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
			createInfo.pApplicationInfo = &appInfo;

			// Extensions to interact with vulkan apis
			uint32_t glfwExtensionCount = 0;
			const char** glfwExtensions;

			glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

			createInfo.enabledExtensionCount = glfwExtensionCount;
			createInfo.ppEnabledExtensionNames = glfwExtensions;
			createInfo.enabledLayerCount = 0;

			if(vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS){ // Creates vulkan instance and returns VK_SUCCESS if instance was created successfully
				throw std::runtime_error("failed to create  instance!");
			}

			uint32_t extensionCount = 0;
			vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr); // Get the number of extensions available to our vulkan instance
			std::vector<VkExtensionProperties> extensions(extensionCount);
			vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data()); // Get extensions available to our vulkan instance
			std::cout << "All available extensions: " << extensionCount << std::endl;
			for(const auto& extension: extensions){
				std::cout << extension.extensionName << std::endl;
			}
		}
		void mainLoop(){
			while(!glfwWindowShouldClose(window)){
				glfwPollEvents();
			}
		}
		void cleanUp(){
			vkDestroyInstance(instance, nullptr);
			glfwDestroyWindow(window);
			glfwTerminate();
		}
};

int main(){
	BaseShapesVulkan app;
	try{
		std::cout << "opening window" << std::endl;
		app.run();
	} catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
		return  EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
