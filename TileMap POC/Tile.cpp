#include "Tile.hpp"
Tile::Tile(SDL_Texture* texture, int x, int y) :
	_texture{ texture },
	_x{ x },
	_y{ y } {}

Tile::~Tile() = default;

SDL_Texture* Tile::texture() const
{
	return _texture;
}

void Tile::set_texture(SDL_Texture* texture)
{
	this->_texture = texture;
}

int Tile::x() const
{
	return _x;
}

void Tile::set_x(int x)
{
	this->_x = x;
}

int Tile::y() const
{
	return _y;
}

void Tile::set_y(int y)
{
	this->_y = y;
}
