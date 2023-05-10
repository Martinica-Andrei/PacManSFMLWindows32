#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
#include "Animatie.h"
#include "Entitate.h"
#include "EventTimp.h"
class Player : public Entitate {
private:
	Animatie _animatie;
	sf::Vector2f _pozitieCurenta;
public:
	Player(Joc* joc);
	void miscare();
	void input();
	void update() override;

};