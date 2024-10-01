#include "Renderer.hpp"

SDL_Renderer* Renderer::renderer = nullptr;

void Renderer::init()
{
	renderer = SDL_CreateRenderer(Window::current, -1, 0);
}

Renderer::~Renderer()
{
	if (renderer != nullptr)
	{
		SDL_DestroyRenderer(renderer);
	}
}

