#include "CookieProducer.h"
#include <iostream>

void CookieProducer::update(SDL_Event& event)
{
	Button::update(event);
	
}

void CookieProducer::onClick() {
	printf("CookieProducer bought ");
}