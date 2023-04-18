#pragma once
#include "Image.h"
#include <memory>

extern class IImageLoader;

class Window
{
	//The window we'll be rendering to
	SDL_Window* window{};
	//The surface contained by the window
	SDL_Surface* screenSurface{};
	SDL_Renderer* renderer;
	//Whether Window Startup was successful
	bool success;
	// dependency to the ImageLoader
	IImageLoader* imageLoader;

public:
	Window(int width, int height, IImageLoader* imageLoader);
	~Window();
	bool wasSuccessful() { return success; }
	void render(Image* image);
	void clear();
	void present();
	std::unique_ptr<Image> loadImage(const char* path);

	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
};

