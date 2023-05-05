#pragma once
#include <unordered_map>
#include <vector>
#include <string>
// folosesc tiled pentru harta, si am nevoie de json
using namespace std;
class CopacJson {
public:
	unordered_map<string, CopacJson*> copii;
	vector<CopacJson*> copiiVec;
	string data;

	~CopacJson();
	CopacJson() = default;
	CopacJson(const string& data) : data(data) {

	}
};

CopacJson* parseJson(const string& numeFisier);