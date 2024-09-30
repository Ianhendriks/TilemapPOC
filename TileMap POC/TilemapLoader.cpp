#include "TilemapLoader.hpp"k

using namespace nlohmann;
using namespace std;

map<int, SDL_Texture> TilemapLoader::loadTextures(string source)
{
	ifstream tilesetFile(source);
	json tilesetJSON;
	tilesetFile >> tilesetJSON;
	tilesetFile.close();
	
	auto tiletypes = tilesetJSON["tiles"];

	map<int, SDL_Texture> textures;

	for (auto& tiletype : tiletypes) 
	{
		string image = tiletype["image"];
		int textureID = tiletype["id"];
		SDL_Surface* surface = IMG_Load(image.c_str());
		SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer::renderer, surface);
		textures.insert(textureID, texture);
	}
}

Tilemap* TilemapLoader::loadTilemap()
{
	string tilemapLocation = "./tilemap.tmj";
	ifstream tilemapFile(tilemapLocation);

	json tilemapJSON;
	tilemapFile >> tilemapJSON;
	tilemapFile.close();

	auto tileset = tilemapJSON["tilesets"][0];
	string tilesetLocation = tilemapJSON["source"];
	map<int, SDL_Texture> textures = loadTextures(tilesetLocation);

	const int width = tilemapJSON["width"];
	const int height = tilemapJSON["height"];
	Tilemap* tilemap = new Tilemap(width, height);

	auto tiles = tilemapJSON["Layers"][0]["data"];

	//each tileid in JSON
	for (auto& tile : tiles) {
		//each column
		for (int y = 0; y < height; y++) {
			//each row
			for (int x = 0; x < width; x++) {
				Tile* newTile = new Tile();
				
			}
		}
	}
	return tilemap;
}





