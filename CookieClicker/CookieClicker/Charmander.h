#pragma once
#include "GameObject.h"
class Charmander :
    public GameObject
{
    int i{};
    int width{};
    int height{};
    bool patrollingDown{ true };
public:
    Charmander(Window* window) : GameObject("img/Charmander.png", window) {};
    Charmander(Window* window, int x) : GameObject("img/Charmander.png", window) {
        image->x = x;
    };
    Charmander(Window* window, int x, int width, int height) : GameObject("img/Charmander.png", window) {
        image->x = x;
        image->width = width;
        image->height = height;
    }
    void update() override;
};

