#pragma once
#include <vector>
#include "Tile.hpp"

class Layer
{
public:
	Layer(int width, int height);
	~Layer() = default;
	[[nodiscard]] const vector<vector<Tile>>& tiles() const;
	void addTile(int x, int y, const Tile& tile);

private:
	vector<vector<Tile>> _tiles;
};

