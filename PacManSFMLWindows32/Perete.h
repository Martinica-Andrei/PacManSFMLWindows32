#pragma once
#include "ObiectJoc.h"
class Perete : public ObiectJoc {
private:
public:
	int texturaRand;
	int texturaColoana;
	Perete(Joc* joc, const sf::Texture* textura);

};