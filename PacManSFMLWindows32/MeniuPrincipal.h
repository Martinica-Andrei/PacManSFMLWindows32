#pragma once
#include "ObiectJoc.h"
class MeniuPrincipal : public ObiectJoc  {
private:
	sf::Text _numeJoc;
	bool _esteActiv;
public:

	MeniuPrincipal(Joc* joc);

	void desenare()override;

	bool esteActiv() {
		return _esteActiv;
	}

	void activeaza() {
		_esteActiv = true;
	}
	
	void dezactiveaza() {
		_esteActiv = false;
	}
};