#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
#include "Animatie.h"
#include <stack>
#include <unordered_set>
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
	// variabila asta e pentru monstrii,  ca sa ignore usa roz
	std::unordered_set<TIPURI_OBIECTE> peretiColiziune{ TIPURI_OBIECTE::perete, TIPURI_OBIECTE::usa };

	DIR oprireMiscareDirectie();
	void continuareMiscareDirectie(DIR oprireMiscare);
	void miscare();
	void rotire();
	Entitate(Joc* joc);
	void setareDirectieCurenta(DIR directieCurenta);
	DIR directieCurenta() {
		return _directieCurenta;
	}
	const sf::Vector2i& destinatie() {
		return _destinatie;
	}

	void setareCoordonate(int rand, int coloana);
	sf::Vector2i coordonateMatrice();
	std::stack<DIR> drumCatreCoordonate(int rand, int coloana);
};