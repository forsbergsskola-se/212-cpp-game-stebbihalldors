/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include <map>
#include <memory>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 1900;
const int SCREEN_HEIGHT = 1000;

const std::map<SDL_KeyCode, const char*> surfaceMap = {
	{SDL_KeyCode::SDLK_UP, "img/up.bmp"},
	{SDL_KeyCode::SDLK_DOWN, "img/down.bmp"},
	{SDL_KeyCode::SDLK_LEFT, "img/left.bmp"},
	{SDL_KeyCode::SDLK_RIGHT, "img/right.bmp"}
};
const char* fallbackSurface{ "img/press.bmp" };




int main(int argc, char* args[])
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	//Start up SDL and create window
	if (!window.wasSuccessful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}


	//Load media
	auto image = std::make_unique<Image>(fallbackSurface);
	if (!image->wasSuccessful())
	{
		printf("Failed to load media!\n");
		return -1;
	}

	// while(!window.quit())
	//     window.update();

	//Hack to get window to stay up
	SDL_Event e; bool quit = false;
	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT: {
				quit = true;
			} 	 break;
			case SDL_KEYDOWN: {
				if (auto result = surfaceMap.find((SDL_KeyCode)e.key.keysym.sym); result != surfaceMap.end()) {
					auto value = *result;
					auto imageName = value.second;
					image = std::make_unique<Image>( imageName );
					if (!image->wasSuccessful())
					{
						printf("Failed to load media!\n");
						return -1;
					}
				}
				else
				{
					image = std::make_unique<Image>(fallbackSurface);
					if (!image->wasSuccessful())
					{
						printf("Failed to load media!\n");
						return -1;
					}
				}
			} break;
			}
			window.render(image.get());
		}
	}
	return 0;
}







