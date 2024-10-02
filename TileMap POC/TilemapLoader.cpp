#include "TilemapLoader.hpp"

map<int, Texture> TilemapLoader::loadTextures(basic_json<>& tilesets)
{
	map<int, Texture> textures;
	for(auto& tileset : tilesets)
	{
		string source = tileset["source"];
		int firstgid = tileset["firstgid"];
		ifstream tilesetFile(source);
		json tilesetJSON;
		tilesetFile >> tilesetJSON;
		tilesetFile.close();

		auto tiletypes = tilesetJSON["tiles"];

		for (basic_json<>& tiletype : tiletypes)
		{
			string image = tiletype["image"];
			int imageID = tiletype["id"];
			int textureID = imageID + firstgid;
			int width = tiletype["imagewidth"];
			int height = tiletype["imageheight"];
			SDL_Surface* surface = IMG_Load(image.c_str());
			SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer::renderer, surface);
			SDL_FreeSurface(surface);
			Texture newTexture(texture, width, height);
			textures.emplace(textureID, newTexture);
		}
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

	//get all tilesets and convert to textures
	auto tilesets = tilemapJSON["tilesets"];
	map<int, Texture> textures = loadTextures(tilesets);

	auto layers = tilemapJSON["layers"];
	const int width = tilemapJSON["width"];
	const int height = tilemapJSON["height"];
	
	Tilemap tilemap;

	for(auto& layer : layers)
	{
		auto tiles = layer["data"];
		Layer newLayer(width, height);

		for (size_t index = 0; index < tiles.size(); ++index) {
			int tileID = tiles[index].get<int>();
			int x = index % width;
			int y = index / width;

			Tile newTile(textures[tileID], x, y);
			newLayer.addTile(x, y, newTile);
		}
		tilemap.addLayer(newLayer);
	}

	return tilemap;
}







