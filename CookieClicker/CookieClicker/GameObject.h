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
	GameObject(const char* imagePath, Window* window, int width, int height);
	virtual void update(SDL_Event& event){}
	void render(Window* window);
};

