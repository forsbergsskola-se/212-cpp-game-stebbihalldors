#include "CookieProducer.h"
#include <iostream>
#include "Cookie.h"

void CookieProducer::handleInput(SDL_Event& event)
{
	Button::handleInput(event);
}

void CookieProducer::update()
{
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

	printf("CookieProducer Cost: %d\n", producerCost);
	totalProducers++;
	cookie->totalCookies -= producerCost;
	producerCost *= 2;

	printf("CookieProducers: %d\n", totalProducers);
}

int CookieProducer::getTotalProducers()
{
	return totalProducers;
}

int CookieProducer::getProducerCost()
{
	return producerCost;
}
