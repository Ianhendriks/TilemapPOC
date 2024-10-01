#include "Layer.hpp"

Layer::Layer(int width, int height) :
	_tiles(width, std::vector<Tile>(height)) {}


void Layer::addTile(int x, int y, const Tile& tile)
{
	_tiles[x][y] = tile;
}

const vector<vector<Tile>>& Layer::tiles() const
{
	return _tiles;
}