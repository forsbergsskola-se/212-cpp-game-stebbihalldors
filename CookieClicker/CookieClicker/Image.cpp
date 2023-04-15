#include "Image.h"
#include <SDL.h>
#include <cstdio>

Image::Image(SDL_Texture* texture) : 
	texture{ texture },
	success{texture != nullptr},
	x{},
	y{},
	width{}, //add here if we want pikachu to spawn somewhere (curr dont want him)
	height{}
{
	success = true;
}

Image::~Image() {
	//Dealloacate surface
	SDL_DestroyTexture(texture);
	texture = nullptr;
}