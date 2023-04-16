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
	GameObject(const char* imagePath, Window* window, int x, int y, int width, int height);
	virtual void handleInput(SDL_Event& event){}
	virtual void update() {}
	void render(Window* window);
};

