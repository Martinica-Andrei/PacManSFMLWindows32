#pragma once
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class CopacJson {
public:
	unordered_map<string, CopacJson*> copii;
	vector<string> data;

	CopacJson* operator[](const string& str);
	~CopacJson();
};

CopacJson* parseJson(const string& numeFisier);