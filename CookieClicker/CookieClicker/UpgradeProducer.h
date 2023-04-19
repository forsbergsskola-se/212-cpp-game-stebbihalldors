#pragma once
#include "Button.h"

extern class CookieProducer;
extern class Cookie;

class UpgradeProducer :
    public Button
{
    int upgradeCost{ 10 };
    Cookie* cookie;
    CookieProducer* cP;
protected:
    void onClick() override;
public:
    UpgradeProducer(Window* window, int x, int y, int width, int height, CookieProducer* cP, Cookie* cookie) : Button("img/UpgradeProducer.png", window), cP{ cP }, cookie{ cookie } {
        image->x = x;
        image->y = y;
        image->width = width;
        image->height = height;
    };

    void handleInput(SDL_Event& event) override;
    void update() {}
};

