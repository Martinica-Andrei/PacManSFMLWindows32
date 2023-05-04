#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class ObiectJoc;
class Player;
class Joc {
private:
	sf::RenderWindow* _ecran = new sf::RenderWindow(sf::VideoMode(800, 600), "Martinica Andrei-Marian Pac-Man");
public:
	std::vector<ObiectJoc*> obiecte;
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