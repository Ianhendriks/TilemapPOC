#pragma once
#include "Tilemap.hpp"
#include <SDL2/SDL.h>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

class TilemapLoader
{
public:
	Tilemap* loadTilemap();

private:
};
