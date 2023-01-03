#include "engine_pipeline.hpp"
#include <cstddef>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <iostream>

namespace engine{
	
	EnginePipeline::EnginePipeline(const std::string& vertFilepath, const std::string& fragFilepath){
		createGraphicsPipeline(vertFilepath, fragFilepath);
	}

	std::vector<char> EnginePipeline::readFile(const std::string& filePath){
		std::ifstream file(filePath, std::ios::ate | std::ios::binary);  // seek to end to get file size
		if(!file.is_open()) throw std::runtime_error("Unable to open file " + filePath);
		size_t fileSize = static_cast<size_t>(file.tellg()); // tellg tells returns current position of pointer in file, which is actually the size of the file.
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}

	void EnginePipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath){

		auto vertCode = readFile(vertFilepath);
		auto fragCode = readFile(fragFilepath);
		
		std::cout << "Size of vertex shader file is : " << vertCode.size() << " and Frag shader file: " << fragCode.size() << std::endl;
	}
}
