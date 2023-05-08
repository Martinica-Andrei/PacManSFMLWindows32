#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
#include "Animatie.h"
class Entitate : public ObiectJoc {
protected:
	DIR _directieCurenta = DIR::null;
	sf::Vector2f _pozitieCurenta;
	int _rand = 0;
	int _coloana = 0;
	sf::Vector2i _destinatie;
public:
	const sf::Vector2f& pos;
	const sf::Vector2f& scale;
	float _velocitate = 0;
	virtual void miscare();

	Entitate(Joc* joc);
};