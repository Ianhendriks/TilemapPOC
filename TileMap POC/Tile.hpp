#pragma once
#include <string>

#include "Texture.hpp"
#include "SDL2/SDL.h" 
using namespace std;

class Tile
{
public:
	Tile() : _texture(), _x(0), _y(0) {}
	Tile(Texture& texture, int x, int y);
	~Tile() = default;

	Tile(const Tile&) = default;
	Tile& operator=(const Tile&) = default;
	Tile(Tile&&) noexcept = default;
	Tile& operator=(Tile&&) noexcept = default;

	const Texture& texture() const;
	void set_texture(Texture& texture);
	int x() const;
	void set_x(int x);
	int y() const;
	void set_y(int y);

		
private:
	Texture _texture;
	int _x;
	int _y;
};

