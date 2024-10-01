#include <iostream>
#include "Renderer.hpp"
#include "TilemapLoader.hpp"
#include "Window.hpp"
#include "SDL2/SDL.h" 
using namespace std;

int main(int argc, char *argv[])
{
    //init and load tiles
    SDL_Init(SDL_INIT_EVERYTHING);
    Window::init();
    Renderer::init();
    TilemapLoader loader;
    Tilemap tilemap = loader.loadTilemap();

    //run sdl program
    bool running{ true };

    while (running)
    {
        const int tileWidth = 32;
        const int tileHeight = 32;

        //render tiles
        SDL_RenderClear(Renderer::renderer);

        for (const auto& row : tilemap.tiles()) {
            for (const auto& tile : row) {
                SDL_Rect Rect = { tile.x() * tileWidth, tile.y() * tileHeight, tileWidth, tileHeight };
                SDL_RenderCopy(Renderer::renderer, tile.texture(), nullptr, &Rect);
            }
        }

        SDL_RenderPresent(Renderer::renderer);

        //events
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
    }
    return 0;
}
