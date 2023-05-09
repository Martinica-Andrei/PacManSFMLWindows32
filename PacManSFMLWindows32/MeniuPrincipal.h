#pragma once
#include "ObiectJoc.h"
#include "Buton.h"
class MeniuPrincipal : public ObiectJoc  {
private:
	sf::Text _numeJoc;
	Buton* _butonJoaca;
	bool _esteActiv;
public:

	MeniuPrincipal(Joc* joc);
	~MeniuPrincipal();
	void desenare()override;
	void update() override;
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