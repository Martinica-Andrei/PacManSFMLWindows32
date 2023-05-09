#include "MeniuPrincipal.h"
#include "Joc.h"
MeniuPrincipal::MeniuPrincipal(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })) {
	const auto& marimeEcran = _joc->ecran()->getSize();
	_numeJoc = sf::Text("PAC-MAN", _joc->font, 80);
	_numeJoc.setPosition((marimeEcran.x - _numeJoc.getGlobalBounds().width) / 2, 100);
}

void MeniuPrincipal::desenare() {
	_joc->ecran()->draw(_numeJoc);
}