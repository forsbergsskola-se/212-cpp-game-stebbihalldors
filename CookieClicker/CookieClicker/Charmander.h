#pragma once
#include "GameObject.h"
#include "Button.h"
class Charmander :
    public Button
{
    bool patrollingDown{ true };
protected:
    void onClick() override;
public:
    int totalCookies{};
    Charmander(Window* window) : Button("img/Charmander.png", window) {};
    Charmander(Window* window, int x) : Button("img/Charmander.png", window) {
        image->x = x;
    };
    Charmander(Window* window, int x, int y, int width, int height) : Button("img/Charmander.png", window) {
        image->x = x;
        image->y = y;
        image->width = width;
        image->height = height;
    };
    void update(SDL_Event& event) override;
};

