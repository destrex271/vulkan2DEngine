#include <exception>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

class BaseShapesVulkan{
	public:
		void run(){
			initWindow();
			initVulkan();
			mainLoop();
			cleanUp();
		}
	
	private:
		
		GLFWwindow* window;

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
		void initVulkan(){}
		void mainLoop(){
			while(!glfwWindowShouldClose(window)){
				glfwPollEvents();
			}
		}
		void cleanUp(){
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
