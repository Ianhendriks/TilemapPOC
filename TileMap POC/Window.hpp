#pragma once
#include <SDL2/SDL_video.h>

class Window
{
public:
	static SDL_Window* current;
	static void init();

private:
	Window() = default;
	~Window();
};	
