#include "TilemapLoader.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace nlohmann;
using namespace std;

Tilemap* TilemapLoader::loadTilemap()
{
	ifstream tilemapFile("./tilemap.tmj");

	json tilemapJSON;
	tilemapFile >> tilemapJSON;
	tilemapFile.close();

	basic_json<> tiles = tilemapJSON["layers"];
	int width = tilemapJSON["tilewidth"];
	int height = tilemapJSON["tileheight"];
	auto tileset = tilemapJSON["tilesets"];
	string tilesetSource = tileset["source"];

	Tilemap* tilemap = new Tilemap(width, height);

	for (const auto& row : tilemapJSON["tiles"]) {
		for (const auto& tile : row) {
			std::cout << tile << " ";
		}
	}

	return tilemap;
}

