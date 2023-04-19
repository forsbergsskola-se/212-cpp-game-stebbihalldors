#include "UpgradeProducer.h"
#include "CookieProducer.h"
#include "Cookie.h"
#include <iostream>

void UpgradeProducer::handleInput(SDL_Event& event)
{
	Button::handleInput(event);
}

void UpgradeProducer::onClick() {
	if (upgradeCost > cookie->totalCookies) return;

	printf("Upgrade Cost: %d\n", upgradeCost);
	cookie->totalCookies -= upgradeCost;
	upgradeCost *= 4;

	cP->upgradeProducer++;
	printf("Producer Level: %d\n", cP->upgradeProducer);
}