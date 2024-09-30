#include <vector>
#include "Tile.hpp"

using namespace std;

class Tilemap {
public:
	Tilemap(int width, int height);
	~Tilemap();

	void addNewTile(int x, int y, Tile tile);

private:
	vector<vector<Tile>> _tiles;
};