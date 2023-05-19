#include <fstream>
#include <iostream>
#include "JsonParser.h"
namespace {
	
	CopacJson* _parseCheie(string& jsonString, CopacJson* nod, int& index);
	void _parseValoare(string& jsonString, CopacJson* nod, int& index);
	void _parseArray(string& jsonString, CopacJson* nod, int& index);
	void _parseJson(string& jsonString, CopacJson* nod, int& index);

	CopacJson* _parseCheie(string& jsonString, CopacJson* nod , int& index){
		int i;
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
		return nodNou;
	}

	void _parseValoare(string& jsonString, CopacJson* nod, int& index) {
		int i;
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

	void _parseArray(string& jsonString, CopacJson* nod, int& index) {
		while (index < jsonString.size()) {			
			if (jsonString[index] == ']') {
				index++;
				break;
			}
			if (jsonString[index] == ',') {
				index++;
			}
			if (jsonString[index] == '[') {
				index++;
				CopacJson* nodNou = new CopacJson();
				nod->copiiVec.push_back(nodNou);
				_parseArray(jsonString, nodNou, index);
				continue;
			}
			else if (jsonString[index] == '{') {
				index++;
				CopacJson* nodNou = new CopacJson();
				nod->copiiVec.push_back(nodNou);
				_parseJson(jsonString, nodNou, index);
				continue;
			}
			int i;
			if (jsonString[index] == '\"') {
				index++;
				for (i = index; jsonString[i] != '\"'; i++);
				nod->copiiVec.push_back(new CopacJson(jsonString.substr(index, i - index)));
				i++;
			}
			else {
				for (i = index; jsonString[i] != ',' && jsonString[i] != ']'; i++);
				nod->copiiVec.push_back(new CopacJson(jsonString.substr(index, i - index)));
			}
			index = i;
		}
	}

	void _parseJson(string& jsonString, CopacJson* nod, int& index) {
		while (index < jsonString.size() && jsonString[index] != ']') {
			if (jsonString[index] == '}' ||  jsonString[index] == ',') {
				index++;
				break;
			}
			if (jsonString[index] == '\"') {
				index++;
				CopacJson* nodNou = _parseCheie(jsonString, nod, index);
				_parseJson(jsonString, nodNou, index);
			}
			else if (jsonString[index] == ':') {
				index++;
				if (jsonString[index] == '{') {
					index++;
				}
				else if (jsonString[index] == '[') {
					index++;
					_parseArray(jsonString, nod, index);
				}
				else {
					_parseValoare(jsonString, nod, index);
				}
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

CopacJson& CopacJson::operator[](const string& str) {
	return *copii[str];
}

CopacJson& CopacJson::operator[](int index) {
	return *copiiVec[index];
}