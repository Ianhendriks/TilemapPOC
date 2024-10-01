#pragma once
#include <vector>
#include "Layer.hpp"

using namespace std;

class Tilemap {
public:
	Tilemap() = default;
	~Tilemap() = default;
	const vector<Layer>& layers() const;
	void addLayer(const Layer& layer);

private:
	vector<Layer> _layers;
};