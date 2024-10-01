#include "Tile.hpp"
Tile::Tile(Texture& texture, int x, int y) :
	_texture{ texture },
	_x{ x },
	_y{ y } {}

const Texture& Tile::texture() const
{
	return _texture;
}

void Tile::set_texture(Texture& texture)
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
