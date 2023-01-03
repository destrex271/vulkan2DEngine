#pragma once

#include <string>
#include <vector>

namespace engine{
	class EnginePipeline{
		public:
			EnginePipeline(const std::string& vertFilepath, const std::string& fragFilepath);

		private:
			static std::vector<char> readFile(const std::string& filePath);

			void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath); 
	};
}
