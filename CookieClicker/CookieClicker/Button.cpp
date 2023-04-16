#include "Button.h"
#include <iostream>

void Button::handleInput(SDL_Event& event)
{
		switch (event.type)
		{
			case SDL_MOUSEMOTION: {
				
			} break;
			case SDL_MOUSEBUTTONDOWN: {
				int x, y;
				SDL_GetMouseState(&x, &y);
				
				if (x > this->image->x && x < this->image->width + this->image->x && y > this->image->y && y < this->image->height + this->image->y && SDL_BUTTON_LEFT == event.button.button) 
				{
					onClick();
					if(!hasPressed)
					{
						this->image->width -= 20;
						this->image->height -= 20;
						hasPressed = true;
					}
				}
			} break;
			case SDL_MOUSEBUTTONUP: {
				int x, y;
				SDL_GetMouseState(&x, &y);
				
				if(hasPressed)
				{
					this->image->width += 20;
					this->image->height += 20;
					hasPressed = false;
				}
			} break;
		}
	
}
