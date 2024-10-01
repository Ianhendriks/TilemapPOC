#include "Tilemap.hpp"

Tilemap::Tilemap(int width, int height) :
	_tiles(width, std::vector<Tile>(height)) {}

Tilemap::~Tilemap() = default;

void Tilemap::addNewTile(int x, int y, Tile tile)
{
	_tiles[x][y] = tile;
}

vector<vector<Tile>> Tilemap::tiles() const
{
	return _tiles;
}

