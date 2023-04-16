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
#include "Charmander.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

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

	int gHeight = 200;
	int gWidth = 200;
	//Normal images
	gameObjects.push_back(new GameObject{ "img/Background.jpg", &window , 0,0,1024, 768 }); // Image without a button (not clickable)
	gameObjects.push_back(new GameObject{ "img/VLine.png", &window, (SCREEN_WIDTH/2)+(SCREEN_WIDTH/6), -200, 200, 1500 }); // Image without a button (not clickable)
	//Button images
	gameObjects.push_back(new Charmander{ &window, 0, (SCREEN_HEIGHT/2)-gHeight/2 , gHeight, gWidth});
	
	//todo: Make a background image first, 
	
	//Second: Make a buyMenu image on the right quarter of the screen where buttons will come ontop
	//gameObjects.push_back(new Charmander{ &window,400, 400 , 200, 200});

	// while the user doesnt want to quit
	SDL_Event e; bool quit = false;
	unsigned int frameStartMs;
	bool goingRight = true;

	while (quit == false)
	{
		frameStartMs = SDL_GetTicks();

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
				} break;
			}
			for (auto gameObject : gameObjects) {
				gameObject->update(e);
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







