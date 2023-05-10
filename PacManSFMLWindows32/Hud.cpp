#include "Hud.h"
#include "Joc.h"

Hud::Hud(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })) {
	_textScor.setFont(_joc->font);
	_textScor.setPosition(10, 10);
	resetare();
}
Hud::~Hud() {

}

void Hud::adaugareScor(int val) {
	_scor += val;
	_textScor.setString("SCOR : " + std::to_string(_scor));
}


void Hud::desenare() {
	_joc->ecran()->draw(_textScor);
	for (auto& viata : _vieti) {
		viata->desenare();
	}
}

void Hud::resetare() {
	adaugareScor(-_scor);
	for (auto& viata : _vieti) {
		delete viata;
	}
	_vieti.clear();
	int y = 560;
	int x = 100;
	for (int i = 0; i < 3; i++) {
		ObiectJoc* viata = new ObiectJoc(_joc, new sf::RectangleShape({ 1,1 }));
		viata->forma().setScale(30, 30);
		viata->forma().setPosition(x, y);
		viata->forma().setTexture(&_joc->texturi.pacman_1);
		x += 35;
		_vieti.push_back(viata);
	}
}