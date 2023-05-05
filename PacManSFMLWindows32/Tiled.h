#pragma once
#include "JsonParser.h"
class Tiled {
private:
	CopacJson* _json;
public:
	vector<int> data;
	Tiled(const std::string& numeFisier);
	~Tiled();

	CopacJson& json() {
		return *_json;
	}
};