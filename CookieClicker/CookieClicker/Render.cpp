#include "Render.h"
#include "SDL.h"
#include "SDL_image.h"
#include <cstdio>


Render::Render(const char* path) : success{} {

	//Load splash image
	imageSurface = IMG_Load(path);
	if (!imageSurface)
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return;
	}

	success = true;

}

Render::~Render() {
	//Dealloacate surface
	SDL_FreeSurface(imageSurface);
	imageSurface = nullptr;
}