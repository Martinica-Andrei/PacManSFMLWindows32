#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
#include "Animatie.h"
class Entitate : public ObiectJoc {
private:
	DIR _directieCurenta = DIR::null;
	// miscarea se face pe baza de destinatie, iar ea trebuie sa aiba maxim distanta 1 fata de entitate , altfel are probleme
	// distantele sunt pe baza de coordonatele matricei (rand si coloana)
	sf::Vector2i _destinatie;
public:
	const sf::Vector2f& pos;
	const sf::Vector2f& scale;
	float _velocitate = 0;

	DIR oprireMiscareDirectie();
	void continuareMiscareDirectie(DIR oprireMiscare);
	void miscare();
	void rotire();
	Entitate(Joc* joc);
	void setareDirectieCurenta(DIR directieCurenta);
	DIR directieCurenta() {
		return _directieCurenta;
	}
};