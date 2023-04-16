#include "Button.h"
#include <iostream>

void Button::update(SDL_Event& event)
{
		switch (event.type)
		{
			case SDL_MOUSEMOTION: {
				
			} break;
			case SDL_MOUSEBUTTONDOWN: {
				int x, y;
				SDL_GetMouseState(&x, &y);
				
				if (x > this->image->x && x < this->image->width + this->image->x && y > this->image->y && y < this->image->height + this->image->y && SDL_BUTTON_LEFT == event.button.button) {
					onClick();

				}
				if (SDL_BUTTON_LEFT == event.button.button)
					//change to pressed down image
			} break;
			case SDL_MOUSEBUTTONUP: {
				if (SDL_BUTTON_LEFT == event.button.button)
					//default image
			} break;
		}
	
}
