#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace engine{
	class EngineWindow{
		
		public:
			EngineWindow(int w, int h, std::string title);
			~EngineWindow();

			EngineWindow(const EngineWindow&) = delete;
			EngineWindow &operator=(const EngineWindow&) = delete;

			bool shouldClose() {return glfwWindowShouldClose(window);}

		private:	
			void initWindow();
		
			const int WIDTH;
			const int HEIGHT;
			std::string TITLE = "Engine";

			GLFWwindow *window;
	};
} 
