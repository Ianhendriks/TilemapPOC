#include "Tilemap.hpp"

void Tilemap::addLayer(const Layer& layer)
{
	_layers.emplace_back(layer);
}

const vector<Layer>& Tilemap::layers() const
{
	return _layers;
}

