#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
#include "Animatie.h"
#include "Entitate.h"
class Player : public Entitate {
private:
	Animatie _animatie;
public:
	Player(Joc* joc);
	void miscare() override;
	void input();
	void update() override;
};