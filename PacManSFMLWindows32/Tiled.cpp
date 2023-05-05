#include "Tiled.h"

Tiled::Tiled(const std::string& numeFisier) {
	_json = parseJson(numeFisier);
	auto& d = json()["layers"][0]["data"];
	for (auto& v : d.copiiVec) {
		data.push_back(stoi(v->data));
	}
}

Tiled::~Tiled() {
	delete _json;
}