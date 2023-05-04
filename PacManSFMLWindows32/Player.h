#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
class Player : public ObiectJoc {
private:
	DIR _directieCurenta = DIR::null;
public:
	float _velocitate = 200.f;
	Player(Joc* joc);
	void miscare();
	void input();
	void update() override;
};