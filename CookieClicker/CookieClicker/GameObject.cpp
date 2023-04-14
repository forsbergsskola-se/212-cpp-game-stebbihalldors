#include "GameObject.h"
#include "Window.h"

GameObject::GameObject(const char* imagePath, Window* window)
	: image{ window->loadImage(imagePath)}
{
	
}

void GameObject::render(Window* window) {
	window->render(image.get());
}