#include "Image.h"
#include <SDL.h>
#include <cstdio>

SDL_Point getsize(SDL_Texture* texture) {
	SDL_Point size;
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
	return size;
}

Image::Image(SDL_Texture* texture) : 
	texture{ texture },
	success{texture != nullptr},
	x{},
	y{},
	width{}, //add here if we want pikachu to spawn somewhere (curr dont want him)
	height{}
{
	SDL_Point imageSize = getsize(texture);
	width = imageSize.x;
	height = imageSize.y;
	success = true;
}

Image::~Image() {
	//Dealloacate surface
	SDL_DestroyTexture(texture);
	texture = nullptr;
}