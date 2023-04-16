#pragma once
#include "Button.h"
#include "Charmander.h"

class CookieProducer :
    public Button
{
    int i{};
    int totalProducers{1};
    int producerCost{5};
    int totalCookies{};
protected:
    void onClick() override;
public:
    CookieProducer(Window* window) : Button("img/Charmander.png", window) {};
    CookieProducer(Window* window, int x) : Button("img/Charmander.png", window) {
        image->x = x;
    };
    //CookieProducer(Window* window, int x, int y, int width, int height) : Button("img/CookieProducer.png", window) {
    CookieProducer(Window* window, int x, int y, int width, int height , Charmander* charmander) : Button("img/CookieProducer.png", window) {
        image->x = x;
        image->y = y;
        image->width = width;
        image->height = height;
    };
    void getCookies(const Charmander* charmander);
    void update(SDL_Event& event) override;
};

