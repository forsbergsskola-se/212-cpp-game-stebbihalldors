/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include "Window.h"
#include "Image.h"
#include "SDL_ImageImageLoader.h"
#include <vector>
#include "GameObject.h"
#include "Pikachu.h"
#include "Charmander.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

const std::map<SDL_KeyCode, const char*> surfaceMap = {
	{SDL_KeyCode::SDLK_UP, "img/up.bmp"},
	{SDL_KeyCode::SDLK_DOWN, "img/down.bmp"},
	{SDL_KeyCode::SDLK_LEFT, "img/left.bmp"},
	{SDL_KeyCode::SDLK_RIGHT, "img/right.bmp"}
};
const char* fallbackSurface{ "img/Pikachu.png" };

const unsigned int FPS = 30;
const unsigned int MS_PER_FRAME = 1000 / FPS;


int main(int argc, char* args[])
{
	// We decide for now to use the SDL Image Loader ( which only supports BMP)
	IImageLoader* imageLoader = new SDL_ImageImageLoader{};
	// We pass that ImageLoader on to the Window, so the Window can use it
	// to load images
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT,imageLoader };
	//Start up SDL and create window
	if (!window.wasSuccessful())
	{
		printf("Failed to initialize!\n");
		return -1;
	}

	std::vector<GameObject*> gameObjects{};

	gameObjects.push_back(new Pikachu{&window});
	gameObjects.push_back(new Charmander{ &window, 200 , 100, 100});
	gameObjects.push_back(new Charmander{ &window, 400 , 200, 200});

	// while the user doesnt want to quit
	SDL_Event e; bool quit = false;
	unsigned int frameStartMs;
	bool goingRight = true;

	while (quit == false)
	{
		frameStartMs = SDL_GetTicks();

		for (auto gameObject : gameObjects) {
			gameObject->update();
		}
		// loop through all pending events from Windows(OS)
		while (SDL_PollEvent(&e))
		{
			// check, if its an event we want to react to
			switch (e.type)
			{
				case SDL_QUIT: {
					quit = true;
				} 	 break;
				case SDL_MOUSEMOTION: {
					int x, y;
					SDL_GetMouseState(&x, &y);
					std::cout << x << " : " << y << std::endl;
				} break;
				case SDL_MOUSEBUTTONDOWN: {
					if (SDL_BUTTON_LEFT == e.button.button)
						std::cout << "Left mouse button is down" << std::endl;
					if (SDL_BUTTON_RIGHT == e.button.button)
						std::cout << "Right mouse button is down" << std::endl;
					if (SDL_BUTTON_MIDDLE == e.button.button)
						std::cout << "Middle mouse button is down" << std::endl;
				} break;
				case SDL_MOUSEBUTTONUP: {
					if (SDL_BUTTON_LEFT == e.button.button)
						std::cout << "Left mouse button is up" << std::endl;
				} break;
				case SDL_KEYDOWN: {
					const char* imgPath = fallbackSurface;
					if (auto result = surfaceMap.find((SDL_KeyCode)e.key.keysym.sym); result != surfaceMap.end()) {
						imgPath = result->second;
					}
				} break;
			}
		}

		// when done with all pending events, update the rendered screen
		window.clear(); //first clear
		for (auto gameObject : gameObjects) {
			gameObject->render(&window);
		}
		window.present(); // then present it

		// see, how long we should wait so we get 30fps
		//fixed update
		unsigned int frameTimeMs = SDL_GetTicks() - frameStartMs;
		if (frameTimeMs < MS_PER_FRAME)
		{
			SDL_Delay(MS_PER_FRAME - frameTimeMs);
		}
	}
	return 0;
}







