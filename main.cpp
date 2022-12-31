#include "first_app.hpp"
#include "window.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main(){
	engine::FirstApp firstApp{};

	try{
		firstApp.run();
	}catch(const std::exception &e){
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
