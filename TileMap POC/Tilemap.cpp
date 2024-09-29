#include "Tilemap.hpp"

Tilemap::Tilemap(int width, int height) :
	_tiles(width, std::vector<Tile>(height)) {}

