#pragma once
#include "Tiled.h"
#include "ObiectJoc.h"
class Harta : public ObiectJoc {
private:
	Tiled _tiledHarta;
	int _randuri;
	int _coloane;
	float _lungime;
	float _inaltime; 
	std::vector<std::vector<ObiectJoc*>> _matrice;

public:
	Harta(Joc* joc);
	virtual ~Harta();
	void update() override;
	void desenare() override;
};