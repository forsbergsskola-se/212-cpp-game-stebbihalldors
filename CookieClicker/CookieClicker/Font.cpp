#include "Font.h"
#include <cstdio>
#include <SDL_ttf.h>
#include "Image.h"

Font::Font(const char* path, const int size, int x, int y, int width, int height)
    : x{ x }, y{ y }, width{ width }, height{ height }
{
	font = TTF_OpenFont(path, size);
	if (font == nullptr)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		success = true;
	}
}

Font::~Font() {
	//Dealloacate surface
	TTF_CloseFont(font);
	font = nullptr;
}

std::unique_ptr<Image> Font::createText(const char* text, SDL_Renderer* renderer)
{
    SDL_Color textColor = { 255,0,0 };
    
    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    if (textSurface == nullptr)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else
    {
        //Create texture from surface pixels
        auto mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (mTexture == nullptr)
        {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            //Get image dimensions
            auto image = std::make_unique<Image>(mTexture);
            image->x = x;
            image->y = y;
            image->width = width;
            image->height = height;
            return std::move(image);
        }
    }
    return nullptr;
}
