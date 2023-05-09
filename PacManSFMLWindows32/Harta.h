#pragma once
#include "Tiled.h"
#include "ObiectJoc.h"
#include <iostream>
class Harta : public ObiectJoc {
private:
	Tiled _tiledHarta;
	int _randuri;
	int _coloane;
	float _lungimePeColoana;
	float _inaltimePeRand; 
	float _startY = 80;

public:
	std::vector<std::vector<ObiectJoc*>> matrice;
	Harta(Joc* joc);
	virtual ~Harta();
	void update() override;
	void desenare() override;

	float lungimePeColoana() {
		return _lungimePeColoana;
	}

	float inaltimePeRand() {
		return _inaltimePeRand;
	}

	int iaRand(float y) {
		return (y - _startY) / _inaltimePeRand;
	}
	int iaColoana(float x) {
		return x /_lungimePeColoana;
	}

	int randuri() {
		return _randuri;
	}

	int coloane() {
		return _coloane;
	}

	float iaCoordonataColoana(unsigned int coloana) {
		return coloana * _lungimePeColoana;
	}

	float iaCoordonataRand(unsigned int rand) {
		return rand * _inaltimePeRand + _startY;
	}

	ObiectJoc* iaObiect(unsigned int rand, unsigned int coloana);
	enum class arieUnuIndici {
		centru = 0,
		sus = 1,
		dreapta=2,
		jos=3,
		stanga=4,
	};
	std::vector<ObiectJoc*> iaArieUnu(float x, float y);

};