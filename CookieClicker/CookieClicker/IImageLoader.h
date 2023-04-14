#pragma once
#include <memory>

extern class Image; //dont need to know all the details of an image, just have the function of returning any kinds of an image
extern struct SDL_Renderer;

class IImageLoader
{
public:
	virtual std::unique_ptr<Image> loadImage(const char* path, SDL_Renderer* renderer) = 0; //pure virtual function (virtual and abstract = 0)
};

