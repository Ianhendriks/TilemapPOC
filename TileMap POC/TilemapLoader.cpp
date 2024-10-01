#include "TilemapLoader.hpp"

using namespace nlohmann;
using namespace std;

map<int, SDL_Texture*> TilemapLoader::loadTextures(string source)
{
	ifstream tilesetFile(source);
	json tilesetJSON;
	tilesetFile >> tilesetJSON;
	tilesetFile.close();
	
	auto tiletypes = tilesetJSON["tiles"];

	map<int, SDL_Texture*> textures;

	for (basic_json<>& tiletype : tiletypes) 
	{
		string image = tiletype["image"];
		int textureID = tiletype["id"];
		SDL_Surface* surface = IMG_Load(image.c_str());
		SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer::renderer, surface);
		SDL_FreeSurface(surface);
		textures[textureID] = texture;
	}

	return textures;
}

Tilemap TilemapLoader::loadTilemap()
{
	string tilemapLocation = "./tilemap.tmj";
	ifstream tilemapFile(tilemapLocation);

	json tilemapJSON;
	tilemapFile >> tilemapJSON;
	tilemapFile.close();

	basic_json<> tileset = tilemapJSON["tilesets"][0];
	string tilesetLocation = tileset["source"].get<string>();
	map<int, SDL_Texture*> textures = loadTextures(tilesetLocation);

	const int width = tilemapJSON["width"];
	const int height = tilemapJSON["height"];
	Tilemap tilemap(width, height);

	auto tiles = tilemapJSON["layers"][0]["data"];

	for (size_t index = 0; index < tiles.size(); ++index) {
		int tileID = tiles[index].get<int>();
		cerr << tileID << endl;
		int x = index % width; // Column
		int y = index / width; // Row

		SDL_Texture* texture = textures[tileID - 1]; //Tiled adds 1 to tile id JSON so id = 0 can be used for empty space
		Tile newTile(texture, x, y);
		tilemap.addNewTile(x, y, newTile);
	}
	return tilemap;
}







