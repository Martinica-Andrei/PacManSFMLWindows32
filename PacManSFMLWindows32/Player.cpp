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
	forma().setPosition(pozitie);
	_rand = joc->harta->iaRand(pozitie.y);
	_coloana = joc->harta->iaColoana(pozitie.x);
	_velocitate = 150.f;
}

void Player::miscare() {
	_pozitieCurenta = forma().getPosition();
	Entitate::miscare();

}

void Player::input() {
	auto& pos = forma().getPosition();
	ObiectJoc* sus = _joc->harta->iaObiect(_rand - 1, _coloana);
	ObiectJoc* dreapta = _joc->harta->iaObiect(_rand, _coloana + 1);
	ObiectJoc* jos = _joc->harta->iaObiect(_rand + 1, _coloana);
	ObiectJoc* stanga = _joc->harta->iaObiect(_rand, _coloana - 1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && (sus == nullptr || sus->tipObiect() != TIPURI_OBIECTE::perete)) {
		_directieCurenta = DIR::sus;
		_destinatie = { _coloana,_rand - 1 };
		forma().setPosition(_joc->harta->iaCoordonataColoana(_coloana) + _joc->harta->lungimePeColoana() / 2, pos.y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && (dreapta == nullptr || dreapta->tipObiect() != TIPURI_OBIECTE::perete)) {
		_directieCurenta = DIR::dreapta;
		_destinatie = { _coloana + 1,_rand };
		forma().setPosition(pos.x, _joc->harta->iaCoordonataRand(_rand) + _joc->harta->inaltimePeRand() / 2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && (jos == nullptr || jos->tipObiect() != TIPURI_OBIECTE::perete)) {
		_directieCurenta = DIR::jos;
		_destinatie = { _coloana,_rand + 1 };
		forma().setPosition(_joc->harta->iaCoordonataColoana(_coloana) + _joc->harta->lungimePeColoana() / 2, pos.y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && (stanga == nullptr || stanga->tipObiect() != TIPURI_OBIECTE::perete)) {
		_directieCurenta = DIR::stanga;
		_destinatie = { _coloana - 1,_rand };
		forma().setPosition(pos.x, _joc->harta->iaCoordonataRand(_rand) + _joc->harta->inaltimePeRand() / 2);
	}

}

void Player::update() {
	input();
	miscare();
	sf::Vector2f distantaTraversata = (_pozitieCurenta - forma().getPosition());
	_animatie.adaugareContor(abs(distantaTraversata.x) + abs(distantaTraversata.y));
	forma().setTexture(_animatie.texturaCurenta());

	ObiectJoc* centru = _joc->harta->iaObiect(_rand, _coloana);
	if (centru != nullptr) {
		centru->coliziune(*this);
	}

}