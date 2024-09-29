#pragma once
#include <SDL2/SDL_render.h>

#include "Window.hpp"


class Renderer
{
public:
	static SDL_Renderer* renderer;
	void init()
	{
		renderer = SDL_CreateRenderer(Window::current, -1, 0);
	}
private:
	Renderer() {}
	~Renderer() {}
};
