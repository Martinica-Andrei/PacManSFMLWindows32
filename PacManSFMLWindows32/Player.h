#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
class Player : public ObiectJoc {
private:
	DIR _directieCurenta = DIR::null;
	float _velocitate = 30.f;
public:

	Player(Joc* joc);
	void miscare();
	void input();
	void update() override;
};