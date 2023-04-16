#pragma once
#include "GameObject.h"
#include "Button.h"
class Cookie :
    public Button
{
    bool patrollingDown{ true };
protected:
    void onClick() override;
public:
    int totalCookies{};
    Cookie(Window* window) : Button("img/Cookie.png", window) {};
    Cookie(Window* window, int x) : Button("img/Cookie.png", window) {
        image->x = x;
    };
    Cookie(Window* window, int x, int y, int width, int height) : Button("img/Cookie.png", window) {
        image->x = x;
        image->y = y;
        image->width = width;
        image->height = height;
    };
    void update(SDL_Event& event) override;
};

