#pragma once
#include <SDL2/SDL_render.h>

#include "Window.hpp"


class Renderer
{
public:
	static SDL_Renderer* renderer;

	static void init();

private:
	Renderer() = default;
	~Renderer();
};
