#include "Image.h"
#include <SDL.h>
#include <cstdio>

Image::Image(const char* path, const SDL_PixelFormat* pixelFormat) : 
	success{},
	x{},
	y{},
	width{ 100 },
	height{ 100 }
{

	//Load splash image
	auto tmpSurface = SDL_LoadBMP(path);
	if (!tmpSurface)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return;
	}

	imageSurface = SDL_ConvertSurface(tmpSurface,pixelFormat, 0);
	SDL_FreeSurface(tmpSurface);
	if (!imageSurface)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return;
	}

	success = true;

}

Image::~Image() {
	//Dealloacate surface
	SDL_FreeSurface(imageSurface);
	imageSurface = nullptr;
}