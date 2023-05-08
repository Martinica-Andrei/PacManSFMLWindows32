#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Joc;
class Animatie {
private:
	Joc* _joc;
	float _contorSecunde = 0;
	int _indexCurent = 0;
	std::vector<const sf::Texture*> texturi;
public:
	float secundePeFrame = 0;

	// dau pass by value vectorul deoarece e mic
	Animatie(Joc* joc, std::vector<const sf::Texture*> texturi) : _joc(joc), texturi(texturi) {

	}

	Animatie(Joc* joc, std::vector<const sf::Texture*> texturi, float secundePeFrame) :Animatie(joc, texturi) {
		this->secundePeFrame = secundePeFrame;
	}

	void update();
	const sf::Texture* texturaCurenta() {
		return texturi[_indexCurent];
	}

	void reset();
	void adaugareContor(float valoare);
};