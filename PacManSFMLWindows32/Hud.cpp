#include "Hud.h"
#include "Joc.h"

Hud::Hud(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })) {
	_textScor.setFont(_joc->font);
	_textScor.setPosition(10, 10);
	adaugareScor(0);
}
Hud::~Hud() {

}

void Hud::adaugareScor(int val) {
	_scor += val;
	_textScor.setString("SCOR : " + std::to_string(_scor));
}


void Hud::desenare() {
	_joc->ecran()->draw(_textScor);
}