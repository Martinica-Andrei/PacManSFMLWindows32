#include "JsonParser.h"
#include <fstream>
#include <iostream>
namespace {
	void _parseJson(string& jsonString, CopacJson* nod, int& index) {
		while (index < jsonString.size()) {
			if (jsonString[index] == '}' || jsonString[index] == ',') {
				index++;
				break;
			}
			int i;
			if (jsonString[index] == '\"') {
				index++;
				for (i = index; jsonString[i] != '\"'; i++);
				CopacJson* nodNou = new CopacJson();
				string  keie = jsonString.substr(index, i - index);
				if (nod->copii.count(keie)) {
					std::cout << "JSON keie " << keie << " este dublura!!\n";
				}
				else {
					nod->copii[keie] = nodNou;
				}
				i++;
				if (i >= jsonString.size() || jsonString[i] != ':') {
					std::cout << "Lipseste : dupa keia : " << keie << '\n';
				}
				index = i;
				_parseJson(jsonString, nodNou, index);
			}
			else if (jsonString[index] == ':') {
				index++;
				if (jsonString[index] == '{') {
					index++;
					continue;
				}
				if (jsonString[index] == '\"') {
					index++;
					for (i = index; jsonString[i] != '\"'; i++);
					nod->data = jsonString.substr(index, i - index);
					i++;
				}
				else {
					for (i = index; jsonString[i] != ',' && jsonString[i] != '}'; i++);
					nod->data = jsonString.substr(index, i - index);
				}
				index = i;		
			}
		}
	}
}

CopacJson::~CopacJson() {
	for (auto& kv : copii) {
		delete kv.second;
	}
}

CopacJson* parseJson(const string& numeFisier) {
	CopacJson* copacJson = new CopacJson();
	ifstream fisier(numeFisier);
	if (fisier.is_open()) {
		string jsonString = "";
		while (fisier.eof() == false) {
			string cuvant;
			// fisier >> cuvant asigura faptul ca nu exista spatii intre stringuri
			fisier >> cuvant;
			jsonString += cuvant;
		}
		if (jsonString.size() > 0) {
			int index = 0;
			if (jsonString[0] == '{') {
				index++;
			}
			_parseJson(jsonString, copacJson, index);
		}
		fisier.close();
	}
	return copacJson;
}