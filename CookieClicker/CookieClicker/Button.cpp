#include "Button.h"
#include <iostream>

void Button::update(SDL_Event& event)
{
	switch (event.type)
	{
		case SDL_MOUSEMOTION: {
			int x, y;
			SDL_GetMouseState(&x, &y);
			std::cout << x << " : " << y << std::endl;
		} break;
		case SDL_MOUSEBUTTONDOWN: {
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (x < this->mPosition.x + this->image->width) {
				onClick();

			}
			if (SDL_BUTTON_LEFT == event.button.button)
				std::cout << "Left mouse button is down" << std::endl;
		} break;
		case SDL_MOUSEBUTTONUP: {
			if (SDL_BUTTON_LEFT == event.button.button)
				std::cout << "Left mouse button is up" << std::endl;
		} break;
	}
}

void Button::setPosition(int x, int y)
{
    mPosition.x = x;
    mPosition.y = y;
}
