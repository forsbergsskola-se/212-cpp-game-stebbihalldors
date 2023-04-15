#pragma once
#include "GameObject.h"
class Button :
    public GameObject
{
    //Top left position
    SDL_Point mPosition;
protected:
    virtual void onClick() = 0;
public:
    //Sets top left position
    void setPosition(int x, int y);

    void update(SDL_Event& event) override;
};

