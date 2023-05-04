#pragma once
#include <SFML/Graphics.hpp>

class Joc {
private:
	sf::RenderWindow* _ecran = new sf::RenderWindow(sf::VideoMode(800, 600), "Martinica Andrei-Marian Pac-Man");
public:
	
	~Joc() {
		delete _ecran;
	}

	Joc();

	sf::RenderWindow* ecran() {
		return _ecran;
	}
	void start();

	void update();
	void desenare();
};