#pragma once
#include "window.hpp"
#include "engine_pipeline.hpp"

namespace engine{
	class FirstApp{
		
		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 600;

			void run();
		private:
			engine::EngineWindow window{WIDTH, HEIGHT, "Vulkan"};
			engine::EnginePipeline enginePipeline{"./shaders/simpleShader.vert.spv", "./shaders/simpleShader.frag.spv"};
	};
}

