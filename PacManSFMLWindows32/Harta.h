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
		return y / _inaltimePeRand;
	}
	int iaColoana(float x) {
		return x /_lungimePeColoana;
	}

	float iaCoordonataColoana(int coloana) {
		return coloana * _lungimePeColoana;
	}

	float iaCoordonataRand(int rand) {
		return rand * _inaltimePeRand;
	}

	sf::Vector2f iaCoordonata(int rand, int coloana) {
		return { rand * _inaltimePeRand ,coloana * _lungimePeColoana };
	}

	ObiectJoc* iaObiect(float x, float y);
	enum class arieUnuIndici {
		centru = 0,
		sus = 1,
		dreapta=2,
		jos=3,
		stanga=4,
	};
	std::vector<ObiectJoc*> iaArieUnu(float x, float y);

};