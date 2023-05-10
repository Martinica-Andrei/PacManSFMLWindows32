#include "Mancare.h"
#include "Joc.h"
#include "Player.h"
Mancare::Mancare(Joc* joc, bool areAbilitate) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })) {
	_areAbilitate = areAbilitate;
}

void Mancare::coliziune(Player& player) {
	eSters = true;
	if (_areAbilitate) {
		player.adaugareAbilitateImunitate();
		_joc->hud->adaugareScor(50);
	}
	else {
		_joc->hud->adaugareScor(10);
	}

}

Mancare::~Mancare() {
	_joc->harta->nrDeMancaruri--;
}