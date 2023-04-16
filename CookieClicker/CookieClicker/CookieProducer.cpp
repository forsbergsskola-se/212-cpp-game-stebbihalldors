#include "CookieProducer.h"
#include <iostream>
#include "Cookie.h"

void CookieProducer::handleInput(SDL_Event& event)
{
	Button::handleInput(event);
	int totalCookies{}; //needs to get the cookiePointer to the totalCookie
	i++;
	if (i == 20) {
		cookie->totalCookies += totalProducers * upgradeProducer;
		totalCookies += totalProducers * upgradeProducer; //number of cookies produces times producers at fixed time(adding upgrades on producers)
		i = 0;
	}
	//SDL_Delay(5);
	std::cout << "Produces Cookies: " << totalCookies << std::endl;
}

void CookieProducer::onClick() {
	if (producerCost > cookie->totalCookies) return;

	totalProducers++;
	cookie->totalCookies -= producerCost;
	producerCost *= 2;

	printf("CookieProducer++\n");
	printf("%d\n", cookie->totalCookies);
}
