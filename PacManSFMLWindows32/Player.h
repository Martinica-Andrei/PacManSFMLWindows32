#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
#include "Animatie.h"
#include "Entitate.h"
#include "EventTimp.h"
#include "AbilitateImunitate.h"
class Player : public Entitate {
private:
	Animatie _animatie;
	sf::Vector2f _pozitieCurenta;

	AbilitateImunitate* _abilitateImunitate;
public:
	Player(Joc* joc);
	~Player();
	void miscare();
	void input();
	void update() override;

	void adaugareAbilitateImunitate();
};