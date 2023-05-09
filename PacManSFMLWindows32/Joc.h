#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Texturi.h"
#include "Harta.h"
#include <random>
class ObiectJoc;
class Player;
class Joc {
private:
	sf::RenderWindow* _ecran = new sf::RenderWindow(sf::VideoMode(800, 800), "Martinica Andrei-Marian Pac-Man");
	int frameratePeSecunda = 75;
	float _milisecundePeFrame = 1.f / frameratePeSecunda;
public:
	Harta* harta;
	const Texturi texturi;
	std::vector<ObiectJoc*> obiecte;
	float timpDeLaUltimulFrame = 0;
	Player* player;
	~Joc();

	Joc();

	sf::RenderWindow* ecran() {
		return _ecran;
	}
	void start();

	void update();
	void desenare();

};