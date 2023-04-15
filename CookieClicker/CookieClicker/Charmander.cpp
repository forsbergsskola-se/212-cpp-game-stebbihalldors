#include "Charmander.h"

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
	printf("Charmander was clicked.");
}