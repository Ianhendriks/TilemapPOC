#pragma once
#include <SDL2/SDL_video.h>

class Window
{
public:
	static SDL_Window* current;
	void init();

private:
	Window() {}
	~Window() {}
};	
