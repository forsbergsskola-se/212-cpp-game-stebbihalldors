#pragma once
#include "GameObject.h"
class Button :
    public GameObject
{
    bool hasPressed{};
protected:
    virtual void onClick() = 0;
public:
    Button(const char* imagePath, Window* window) : GameObject(imagePath, window) {};
    //Sets top left position

    void handleInput(SDL_Event& event) override;
    void update() {};
};

