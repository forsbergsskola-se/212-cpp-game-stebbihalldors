#include "CookieProducer.h"
#include <iostream>

void CookieProducer::update(SDL_Event& event)
{
	Button::update(event);

	i++;
	if (i == 5) {
		totalCookies += totalProducers * 1; //number of cookies produces times producers at fixed time(adding upgrades on producers)
		i = 0;
	}
	//SDL_Delay(5);
	std::cout << "Produces Cookies: " << totalCookies << std::endl;
}

void CookieProducer::onClick() {
	printf("CookieProducer++\n");
	printf("%d", totalCookies);
}

void CookieProducer::getCookies(const Charmander* charmander)
{
	totalCookies = charmander->totalCookies;
}