#include "Player.h"
#include "Joc.h"
#include <iostream>
Player::Player(Joc* joc) : Entitate(joc),
_animatie(joc, { &joc->texturi.pacman_1, &joc->texturi.pacman_2 }, 25) {
	forma().setScale(38, 38);
	forma().setOrigin(0.5, 0.5);
	forma().setTexture(_animatie.texturaCurenta());
	forma().setRotation(270);
	sf::Vector2f pozitie = { 400, 585 };
	forma().setPosition(joc->harta->iaCoordonataColoana(14) + joc->harta->lungimePeColoana() / 2,
		joc->harta->iaCoordonataRand(23) + joc->harta->inaltimePeRand() / 2);
	_velocitate = 150.f;
}

void Player::miscare() {
	_pozitieCurenta = pos;
	Entitate::miscare();
	Entitate::rotire();
	DIR esteOprit = oprireMiscareDirectie();
	continuareMiscareDirectie(esteOprit);
}

void Player::input() {
	int rand = _joc->harta->iaRand(pos.y);
	int coloana = _joc->harta->iaColoana(pos.x);
	ObiectJoc* sus = _joc->harta->iaObiect(rand - 1, coloana);
	ObiectJoc* dreapta = _joc->harta->iaObiect(rand, coloana + 1);
	ObiectJoc* jos = _joc->harta->iaObiect(rand + 1, coloana);
	ObiectJoc* stanga = _joc->harta->iaObiect(rand, coloana - 1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		if ((sus == nullptr || peretiColiziune.count(sus->tipObiect) == false) &&
			eInRaza(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2, 2, pos.x)) {
			setareDirectieCurenta(DIR::sus);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if ((dreapta == nullptr || peretiColiziune.count(dreapta->tipObiect) == false) &&
			eInRaza(_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2, 2, pos.y)) {
			setareDirectieCurenta(DIR::dreapta);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		if ((jos == nullptr || peretiColiziune.count(jos->tipObiect) == false) &&
			eInRaza(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2, 2, pos.x)) {
			setareDirectieCurenta(DIR::jos);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if ((stanga == nullptr || peretiColiziune.count(stanga->tipObiect) == false) &&
			eInRaza(_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2, 2, pos.y)) {
			setareDirectieCurenta(DIR::stanga);
		}
	}

}

void Player::update() {
	if (pos.x > hotarXStanga && pos.x < _joc->ecran()->getSize().x) {
		input();
	}
	miscare();
	sf::Vector2f distantaTraversata = (_pozitieCurenta - forma().getPosition());
	_animatie.adaugareContor(abs(distantaTraversata.x) + abs(distantaTraversata.y));
	forma().setTexture(_animatie.texturaCurenta());
	int rand = _joc->harta->iaRand(pos.y);
	int coloana = _joc->harta->iaColoana(pos.x);
	ObiectJoc* centru = _joc->harta->iaObiect(rand, coloana);
	if (centru != nullptr) {
		centru->coliziune(*this);
	}
	hotare();

}