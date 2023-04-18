#include "Cookie.h"
#include <iostream>
#include "Window.h"

void Cookie::handleInput(SDL_Event& event)
{
	Button::handleInput(event);
}

void Cookie::onClick() {
	printf("Cookie was clicked.\n");
	++totalCookies;
	std::cout << totalCookies << std::endl;
}