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
#include "Cookie.h"
#include "CookieProducer.h"
#include "UpgradeProducer.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

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
	// gameObject.push_back(new CookieUI(cookie));
	// CookieUI(Cookie* cookie) cookie->addListener(this);
	// CookieUI : ICookieListener
	// CookieUI override onCookieChanged(int newCookies){text.setText(newCookies)};
	Cookie cookie{ &window, 0, (SCREEN_HEIGHT / 2) - gHeight / 2 , gWidth, gHeight };
	gameObjects.push_back(&cookie);
	gameObjects.push_back(new CookieProducer{ &window, SCREEN_WIDTH-210, 10, 200, 100 , cookie});
	gameObjects.push_back(new UpgradeProducer{ &window, SCREEN_WIDTH - 110, 150, 50, 50});

	// while the user doesnt want to quit
	SDL_Event e; bool quit = false;
	unsigned int frameStartMs;

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
			}
			for (auto gameObject : gameObjects) {
				gameObject->handleInput(e);
			}
		}
		for (auto gameObject : gameObjects) {
			gameObject->update();
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







