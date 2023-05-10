#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Texturi.h"
#include "Harta.h"
#include <random>
#include "MeniuPrincipal.h"
#include "Hud.h"
class ObiectJoc;
class Player;
class Monstru;
class Joc {
private:
	sf::RenderWindow* _ecran = new sf::RenderWindow(sf::VideoMode(800, 600), "Martinica Andrei-Marian Pac-Man", sf::Style::Titlebar | sf::Style::Close);
	int frameratePeSecunda = 75;
	float _milisecundePeFrame = 1.f / frameratePeSecunda;
	int _nivel = 1;
public:
	bool eGameOver = false;
	bool eFreeze = false;
	bool incepeNivelNou = false;
	sf::Font font;
	Harta* harta = nullptr;
	Hud* hud;
	const Texturi texturi;
	std::vector<ObiectJoc*> obiecte;
	std::vector<Monstru*> monstrii;
	MeniuPrincipal* meniuPrincipal;
	float timpDeLaUltimulFrame = 0;
	Player* player = nullptr;
	~Joc();

	Joc();

	sf::RenderWindow* ecran() {
		return _ecran;
	}
	void init();

	void update();
	void desenare();

	void creareMonstrii();

	void start();
	void sfarsit();
	void nivelNou();
	void reincarcareEntitati();
	void adaugaMonstru(Monstru* monstru);
};