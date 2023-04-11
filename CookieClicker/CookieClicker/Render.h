#pragma once
#pragma once
#include <SDL.h>
class Render
{
	//The image we will load and show on screen
	SDL_Surface* imageSurface{};
	SDL_Texture* newTexture{};
	bool success;
public:
	Render(const char* path);
	~Render();
	bool wasSuccessful() { return success; }
	SDL_Surface* getResource() { return imageSurface; }
	Render& operator =(Render& other) = delete; //makes it unable to copy images
	//Image& operator =(Image&& other) make the move operator just like with string class

};



