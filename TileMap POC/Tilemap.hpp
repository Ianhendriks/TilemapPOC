#pragma once
#include <vector>
#include "Tile.hpp"

using namespace std;

class Tilemap
{
public:
	Tilemap(int width, int height);
	~Tilemap();

private:
	vector<vector<Tile>> _tiles;

public:
};

