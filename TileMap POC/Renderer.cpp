#include "Renderer.hpp"

SDL_Renderer* Renderer::renderer = SDL_CreateRenderer(Window::current, -1, 0);