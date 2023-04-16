#pragma once
#include "Button.h"
class UpgradeProducer :
    public Button
{
    int upgradeCost{ 10 };
protected:
    void onClick() override;
public:
    UpgradeProducer(Window* window) : Button("img/UpgradeProducer.png", window) {};
    UpgradeProducer(Window* window, int x) : Button("img/UpgradeProducer.png", window) {
        image->x = x;
    };
    UpgradeProducer(Window* window, int x, int y, int width, int height) : Button("img/UpgradeProducer.png", window) {
        image->x = x;
        image->y = y;
        image->width = width;
        image->height = height;
    };

    void handleInput(SDL_Event& event) override;
    void update() {}
};

