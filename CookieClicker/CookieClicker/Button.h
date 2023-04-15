#pragma once
#include "GameObject.h"
class Button :
    public GameObject
{
protected:
    virtual void onClick() = 0;
public:
    Button(const char* imagePath, Window* window) : GameObject(imagePath, window) {};
    //Sets top left position

    void update(SDL_Event& event) override;
};

