#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
#include "Animatie.h"
class Player : public ObiectJoc {
private:
	DIR _directieCurenta = DIR::null;
	Animatie _animatie;
	sf::Vector2f _pozitieCurenta;
public:
	float _velocitate = 200.f;
	Player(Joc* joc);
	void miscare();
	void input();
	void update() override;
};