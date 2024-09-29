#pragma once
#include <string>
#include "SDL2/SDL.h" 
using namespace std;

class Tile
{
public:
	Tile() = default;
	Tile(SDL_Texture* texture, int x, int y);
	~Tile();

	SDL_Texture* texture() const;
	void set_texture(SDL_Texture* texture);
	int x() const;
	void set_x(int x);
	int y() const;
	void set_y(int y);

		
private:
	SDL_Texture* _texture;
	int _x;
	int _y;
};

