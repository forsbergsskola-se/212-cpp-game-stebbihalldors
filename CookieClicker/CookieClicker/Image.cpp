#include "Image.h"
#include <SDL.h>
#include <cstdio>

Image::Image(const char* path) : success{} {

	//Load splash image
	imageSurface = SDL_LoadBMP(path);
	if (!imageSurface)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return;
	}

	//imageSurface = SDL_ConvertSurface(
	
	success = true;

}

Image::~Image() {
	//Dealloacate surface
	SDL_FreeSurface(imageSurface);
	imageSurface = nullptr;
}