#include "Charmander.h"
#include <iostream>

void Charmander::update(SDL_Event& event)
{
	Button::update(event);
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

void Charmander::onClick() {
	printf("Charmander was clicked. ");
	totalCookies += 1;
	std::cout << totalCookies << std::endl;
}