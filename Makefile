CFLAGS = -std=c++17
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

vulkanEngine: *.cpp *.hpp
	g++ $(CFLAGS) -o vulkanEngine *.cpp $(LDFLAGS)
