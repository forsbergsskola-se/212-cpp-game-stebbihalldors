#pragma once
#include "Image.h"
#include <memory>
class Window
{
	//The window we'll be rendering to
	SDL_Window* window{};
	//The surface contained by the window
	SDL_Surface* screenSurface{};
	//Working on: The Window Renderer
	SDL_Renderer* renderer{};
	//Whether Window Startup was successful
	bool success;

public:
	Window(int width, int height);
	~Window();
	bool wasSuccessful() { return success; }
	void render(Image* image);
	std::unique_ptr<Image> loadImage(const char* path);
};

