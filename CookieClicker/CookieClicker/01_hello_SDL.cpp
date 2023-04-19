/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "Window.h"
#include "Image.h"
#include "SDL_ImageImageLoader.h"
#include "GameObject.h"
#include "Cookie.h"
#include "CookieProducer.h"
#include "UpgradeProducer.h"
#include "Font.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

const unsigned int FPS = 30;
const unsigned int MS_PER_FRAME = 1000 / FPS;


int main(int argc, char* args[])
{
	// We decide for now to use the SDL Image Loader ( which only supports BMP)
	IImageLoader* imageLoader = new SDL_ImageImageLoader{};
	//Needs IFontLoader to make this cleaner.
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	}
	
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
	Cookie cookie{ &window, 0, (SCREEN_HEIGHT / 2) - gHeight / 2 , gWidth, gHeight };
	gameObjects.push_back(&cookie);
	CookieProducer cP{ &window, SCREEN_WIDTH - 210, 10, 200, 100 , &cookie };
	gameObjects.push_back(&cP);
	gameObjects.push_back(new UpgradeProducer{ &window, SCREEN_WIDTH - 120, 120, 80, 80, &cP, &cookie});

	Font totalCookieFont{ "font/Pacifico.ttf", 60, 20, 20, 300,90 }; //totalCookie
	Font totalProducersFont{ "font/Pacifico.ttf", 50, SCREEN_WIDTH - 450,10,200,100 }; //totalProducers
	Font producerLvl{ "font/Pacifico.ttf", 30, SCREEN_WIDTH - 200,120,80,80 }; //totalProducers
	// gameObject.push_back(new CookieUI(cookie));
	// CookieUI(Cookie* cookie) cookie->addListener(this);
	// CookieUI : ICookieListener
	// CookieUI override onCookieChanged(int newCookies){text.setText(newCookies)};
	
	

	// while the user doesnt want to quit
	SDL_Event e; bool quit = false;
	unsigned int frameStartMs;

	while (quit == false)
	{
		frameStartMs = SDL_GetTicks();

		std::string a = "Lvl: " + std::to_string(cP.upgradeProducer);
		auto text3 = producerLvl.createText(a.c_str(), window.getRenderer());
		std::string t = "Producers: " + std::to_string(cP.getTotalProducers());
		auto text2 = totalProducersFont.createText(t.c_str(), window.getRenderer());
		//Prints out totalCookies TODO: move to UI Class
		std::string s = "Cookies: " + std::to_string(cookie.totalCookies);
		auto text = totalCookieFont.createText(s.c_str(), window.getRenderer());
		//Prints totalCookies in Title
		SDL_SetWindowTitle(window.getWindow(), s.c_str()); // needs to convert int to char* 

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
		window.render(text.get());
		window.render(text2.get());
		window.render(text3.get());

		window.present(); // then present it

		// see, how long we should wait so we get 30fps
		//fixed update
		unsigned int frameTimeMs = SDL_GetTicks() - frameStartMs;
		if (frameTimeMs < MS_PER_FRAME)
		{
			SDL_Delay(MS_PER_FRAME - frameTimeMs);
		}
	}

	//need to delete the gameObject dynamic ones or unique_ptr them

	return 0;
}







