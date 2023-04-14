/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <map>
#include <memory>
#include <string>
#include "Window.h"
#include "Image.h"

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
	std::unique_ptr<Image> image{ window.loadImage(fallbackSurface) };
	if (!image->wasSuccessful())
	{
		printf("Failed to load media!\n");
		return -1;
	}

	// while the user doesnt want to quit
	SDL_Event e; bool quit = false;
	while (quit == false)
	{
		// loop through all pending events from Windows(OS)
		while (SDL_PollEvent(&e))
		{
			// check, if its an event we want to react to
			switch (e.type)
			{
				case SDL_QUIT: {
					quit = true;
				} 	 break;
				case SDL_KEYDOWN: {
					const char* imgPath = fallbackSurface;
					if (auto result = surfaceMap.find((SDL_KeyCode)e.key.keysym.sym); result != surfaceMap.end()) {
						imgPath = result->second;
					}

					image = window.loadImage(imgPath);
					if (!image->wasSuccessful())
					{
						printf("Failed to load media!\n");
						return -1;
					}
				} break;
			}
			// when done with all pending events, update the rendered screen
			window.render(image.get());
		}
	}
	return 0;
}







