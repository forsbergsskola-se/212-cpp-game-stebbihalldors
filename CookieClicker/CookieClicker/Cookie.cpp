#include "Cookie.h"
#include <iostream>

void Cookie::handleInput(SDL_Event& event)
{
	Button::handleInput(event);
	/*
	if (patrollingDown)
	{
		i++;
		if (i == 100) {
			patrollingDown= false;
		}
	}
	else
	{
		i--;
		if (i == 0)
		{
			patrollingDown = true;
		}
	}
	image->y = i;
	*/
}

void Cookie::onClick() {
	printf("Charmander was clicked. ");
	totalCookies += 1;
	std::cout << totalCookies << std::endl;
	//SDL_SetWindowTitle(window, "Cookies: "); // USE THIS FOR TOTAL COOKIES? if ttf doesnt happen
}