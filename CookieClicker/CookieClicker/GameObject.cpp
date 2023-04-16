#include "GameObject.h"
#include "Window.h"

GameObject::GameObject(const char* imagePath, Window* window)
	: image{ window->loadImage(imagePath)}
{
	
}

GameObject::GameObject(const char* imagePath, Window* window, int x, int y, int width, int height) 
	: image{ window->loadImage(imagePath) }
{
	image->x = x;
	image->y = y;
	image->width = width;
	image->height = height;
}

void GameObject::render(Window* window) {
	window->render(image.get());
}