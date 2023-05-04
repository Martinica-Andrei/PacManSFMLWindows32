#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Joc;
class Animatie {
private:
	Joc* _joc;
	float _contorSecunde = 0;
	int _indexCurent = 0;
	std::vector<const sf::Texture*> _texturi; // poate fi si pointer, dar animatiile is simple
public:
	float secundePeFrame = 0;

	// dau pass by value vectorul deoarece e mic
	Animatie(Joc* joc, std::vector<const sf::Texture*> texturi) : _joc(joc), _texturi(texturi) {

	}

	Animatie(Joc* joc, std::vector<const sf::Texture*> texturi, float secundePeFrame) :Animatie(joc, texturi) {
		this->secundePeFrame = secundePeFrame;
	}

	void update();
	const sf::Texture* texturaCurenta() {
		return _texturi[_indexCurent];
	}

	void reset();
};