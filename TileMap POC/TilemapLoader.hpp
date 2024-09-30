#pragma once
#include "Tilemap.hpp"
#include "Renderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>

class TilemapLoader
{
public:
	map<int, SDL_Texture> loadTextures(string source);
	Tilemap* loadTilemap();	
};
