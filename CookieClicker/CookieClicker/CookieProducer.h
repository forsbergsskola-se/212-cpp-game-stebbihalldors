#pragma once
#include "Button.h"

extern class Cookie;

class CookieProducer :
    public Button
{
    int i{};
    int upgradeProducer{ 1 };
    int totalProducers{1};
    int producerCost{5};
    Cookie* cookie;
protected:
    void onClick() override;
public:
    CookieProducer(Window* window, int x, int y, int width, int height, Cookie* cookie) : Button("img/CookieProducer.png", window), cookie{ cookie } {
        image->x = x;
        image->y = y;
        image->width = width;
        image->height = height;
    };
    void handleInput(SDL_Event& event) override;
    void update() {}

};

