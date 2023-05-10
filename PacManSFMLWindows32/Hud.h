#pragma once
#include "ObiectJoc.h"

class Hud : public ObiectJoc {
private:
	sf::Text _textScor;
	int _scor = 0;
public:

	Hud(Joc* joc);
	~Hud();

	void adaugareScor(int val);

	void desenare() override;
};