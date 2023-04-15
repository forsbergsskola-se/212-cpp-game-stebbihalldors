#pragma once
#include <memory>
#include "Image.h"

extern class Window;


class GameObject
{
protected:
	std::unique_ptr<Image> image;
public:
	GameObject(const char* imagePath, Window* window);
	virtual void update(SDL_Event& event){}
	void render(Window* window);
};

