#include "first_app.hpp"
#include <GLFW/glfw3.h>

namespace engine{
	void FirstApp::run(){
		while(!window.shouldClose()){
			glfwPollEvents();
		}
	}
}
