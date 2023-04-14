#include "SDL_ImageImageLoader.h"
#include <SDL_image.h>
#include "Image.h"

std::unique_ptr<Image> SDL_ImageImageLoader::loadImage(const char* path, const SDL_PixelFormat* pixelFormat)
{
	return std::unique_ptr<Image>{nullptr};
}

SDL_ImageImageLoader::SDL_ImageImageLoader()
{
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
}