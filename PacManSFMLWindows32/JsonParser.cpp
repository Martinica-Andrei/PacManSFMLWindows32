#include "JsonParser.h"

CopacJson* CopacJson::operator[](const string& str) {
	return copii[str];
}

CopacJson::~CopacJson() {
	for (auto& kv : copii) {
		delete kv.second;
	}
}

CopacJson* parseJson(const string& numeFisier) {

}
namespace {
	//CopacJson* _parseJson()
}