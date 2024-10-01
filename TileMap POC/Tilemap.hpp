#include <vector>
#include "Tile.hpp"

using namespace std;

class Tilemap {
public:
	Tilemap(int width, int height);
	~Tilemap();
	[[nodiscard]] vector<vector<Tile>> tiles() const;
	void addNewTile(int x, int y, Tile tile);

private:
	vector<vector<Tile>> _tiles;
};