#include "window.hpp"
#include <GLFW/glfw3.h>
#include <string>

namespace engine{

	EngineWindow::EngineWindow(int w, int h, std::string title): WIDTH{w}, HEIGHT{h}, TITLE{title}{
		initWindow();
	}
	
	EngineWindow::~EngineWindow(){
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void EngineWindow::initWindow(){
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Disable default action to use use opengl 
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(this->WIDTH, this->HEIGHT, this->TITLE.c_str(), nullptr, nullptr);
	}

} 
