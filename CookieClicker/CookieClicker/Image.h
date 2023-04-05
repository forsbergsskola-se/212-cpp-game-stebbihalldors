#pragma once
#include <SDL.h>
class Image
{
	//The image we will load and show on screen
	SDL_Surface* imageSurface{};
	bool success;
public:
	Image(const char* path);
	~Image();
	bool wasSuccessful() { return success; }
	SDL_Surface* getResource() { return imageSurface; }
	Image& operator =(Image& other) = delete; //makes it unable to copy images
	//Image& operator =(Image&& other) make the move operator just like with string class

};

