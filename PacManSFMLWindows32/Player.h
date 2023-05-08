#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
#include "Animatie.h"
class Player : public ObiectJoc {
private:
	DIR _directieCurenta = DIR::null;
	Animatie _animatie;
	sf::Vector2f _pozitieCurenta;
	int _rand = 0;
	int _coloana = 0;
	sf::Vector2i _destinatie;
public:
	float _velocitate = 200.f;
	Player(Joc* joc);
	void miscare();
	void input();
	void update() override;
};