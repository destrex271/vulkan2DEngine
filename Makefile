CFLAGS = -std=c++17
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

vulkanEngine: main.cpp
	g++ $(CFLAGS) -o vulkanEngine main.cpp $(LDFLAGS)
