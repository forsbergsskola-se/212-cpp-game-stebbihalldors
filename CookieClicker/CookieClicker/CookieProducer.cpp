#include "CookieProducer.h"
#include <iostream>
#include "Cookie.h"

void CookieProducer::handleInput(SDL_Event& event)
{
	Button::handleInput(event);
}

void CookieProducer::update()
{
	 //needs to get the cookiePointer to the totalCookie
	i++;
	if (i == 100) {
		cookie->totalCookies += totalProducers * upgradeProducer;
		//cookie->totalCookies += totalProducers * upgradeProducer; //number of cookies produces times producers at fixed time(adding upgrades on producers)
		i = 0;
		std::cout << "Produces Cookies: " << cookie->totalCookies << std::endl;
	}
	//SDL_Delay(5);
	
}

void CookieProducer::onClick() {
	if (producerCost > cookie->totalCookies) return;

	totalProducers++;
	cookie->totalCookies -= producerCost;
	producerCost *= 2;

	printf("CookieProducer++\n");
	printf("%d\n", cookie->totalCookies);
}
