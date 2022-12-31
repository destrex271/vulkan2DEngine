#pragma once
#include "window.hpp"

namespace engine{
	class FirstApp{
		
		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 600;

			void run();
		private:
			engine::EngineWindow window{WIDTH, HEIGHT, "Vulkan"};
	};
}

