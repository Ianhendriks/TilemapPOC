#include "Window.hpp"

SDL_Window* Window::current = nullptr;

void Window::init()
{
	current = SDL_CreateWindow("Tilemap POC", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
}

Window::~Window()
{
	if (current != nullptr)
	{
		SDL_DestroyWindow(current);
	}
}

