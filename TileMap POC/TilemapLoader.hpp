#pragma once
#include "Tilemap.hpp"
#include "Renderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>

using namespace nlohmann;
using namespace std;

class TilemapLoader
{
public:
	TilemapLoader() = default;
	~TilemapLoader() = default;
	Tilemap loadTilemap();

	TilemapLoader(const TilemapLoader&) = delete;
	TilemapLoader& operator=(const TilemapLoader&) = delete;
private:
	map<int, Texture> loadTextures(basic_json<>& tilesets);
};
