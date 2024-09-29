#include <iostream>
#include "Renderer.hpp"
#include "TilemapLoader.hpp"
#include "Window.hpp"
#include "SDL2/SDL.h" 
using namespace std;

int main(int argc, char *argv[])
{
    TilemapLoader loader;
    Tilemap* tilemap = loader.loadTilemap();
    return 0;
    /*SDL_Init(SDL_INIT_EVERYTHING);

    bool running{ true };

    while (running)
    {
        SDL_SetRenderDrawColor(Renderer::renderer, 0, 0, 255, 0);
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_MOUSEMOTION )
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                cout << x << " : " << y << endl;
            }

            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
    }
    return 0;*/
}
