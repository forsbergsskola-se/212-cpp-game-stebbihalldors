#pragma once
#include <memory>
#include <SDL_ttf.h>
extern class Image;

class Font
{
	int x, y, width, height;
	const char* path;
	int size;
	//The image we will load and show on screen
	TTF_Font* font{};
	bool success;
public:
	
	Font(const char* path, const int size, int x, int y, int width, int height);
	~Font();
	bool wasSuccessful() { return success; }
	TTF_Font* getResource() { return font; }
	Font& operator =(Font& other) = delete; //makes it unable to copy images
	Font& operator =(Font&& other) = default; //make the move operator just like with string class
	std::unique_ptr<Image> createText(const char* text, SDL_Renderer* renderer);
};

