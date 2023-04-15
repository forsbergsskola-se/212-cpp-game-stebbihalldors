#include "Button.h"
#include <iostream>

void Button::update(SDL_Event& event)
{
	//std::cout << this->image->x << " : " << this->image->y << std::endl;

		switch (event.type)
		{
			case SDL_MOUSEMOTION: {
				int x, y;
				SDL_GetMouseState(&x, &y);
				//std::cout << x << " : " << y << std::endl;
				if (x > this->image->x && x < this->image->width + this->image->x && y > this->image->y && y < this->image->height + this->image->y) {
					std::cout << "On charmander!" << std::endl;
				}
			} break;
			case SDL_MOUSEBUTTONDOWN: {
				int x, y;
				SDL_GetMouseState(&x, &y);
				
				if (x > this->image->x && x < this->image->width + this->image->x && y > this->image->y && y < this->image->height + this->image->y) {
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
