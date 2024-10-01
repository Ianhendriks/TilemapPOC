#include <iostream>
#include "Renderer.hpp"
#include "TilemapLoader.hpp"
#include "Window.hpp"
#include "SDL2/SDL.h"
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

int main(int argc, char *argv[])
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
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

        for(const auto& layer : tilemap.layers())
        {
            for (const auto& row : layer.tiles()) {
                for (const auto& tile : row) {
                    SDL_Rect Rect = { tile.x() * tileWidth, tile.y() * tileHeight, tile.texture().width(), tile.texture().height() };
                    SDL_RenderCopy(Renderer::renderer, tile.texture().texture(), nullptr, &Rect);
                }
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
                SDL_RenderClear(Renderer::renderer);
                SDL_Quit();
            }
        }
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
