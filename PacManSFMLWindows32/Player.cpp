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
	float viteza = _velocitate * _joc->timpDeLaUltimulFrame;
	ObiectJoc* obiect = _joc->harta->iaObiect(_destinatie.y, _destinatie.x);
	if (obiect != nullptr && obiect->tipObiect() == TIPURI_OBIECTE::perete) return;
	if (_directieCurenta == DIR::sus) {
		forma().move(0, -viteza);
		forma().setRotation(270);

	}
	if (_directieCurenta == DIR::dreapta) {
		forma().move(viteza, 0);
		forma().setRotation(0);

	}
	if (_directieCurenta == DIR::jos) {
		forma().move(0, viteza);
		forma().setRotation(90);

	}
	if (_directieCurenta == DIR::stanga) {
		forma().move(-viteza, 0);
		forma().setRotation(180);

	}
	int rand, coloana;
	auto& pos = forma().getPosition();
	if (_directieCurenta == DIR::sus) {
		rand = _joc->harta->iaRand(pos.y + _joc->harta->inaltimePeRand() / 2);
		coloana = _joc->harta->iaColoana(pos.x);
		if (rand == _destinatie.y && coloana == _destinatie.x) {
			forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2,
				_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
			_destinatie.y--;
		}
	}
	else if (_directieCurenta == DIR::dreapta) {
		rand = _joc->harta->iaRand(pos.y);
		coloana = _joc->harta->iaColoana(pos.x - _joc->harta->lungimePeColoana() / 2);
		if (rand == _destinatie.y && coloana == _destinatie.x) {
			forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2,
				_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
			_destinatie.x++;
		}
	}
	else if (_directieCurenta == DIR::jos) {
		rand = _joc->harta->iaRand(pos.y - _joc->harta->inaltimePeRand() / 2);
		coloana = _joc->harta->iaColoana(pos.x);
		if (rand == _destinatie.y && coloana == _destinatie.x) {
			forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2,
				_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
			_destinatie.y++;
		}
	}
	else if (_directieCurenta == DIR::stanga) {
		rand = _joc->harta->iaRand(pos.y);
		coloana = _joc->harta->iaColoana(pos.x + _joc->harta->lungimePeColoana() / 2);
		if (rand == _destinatie.y && coloana == _destinatie.x) {
			forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2,
				_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
			_destinatie.x--;
		}
	}
}

void Player::input() {
	int rand = _joc->harta->iaRand(pos.y);
	int coloana = _joc->harta->iaColoana(pos.x);
	ObiectJoc* sus = _joc->harta->iaObiect(rand - 1, coloana);
	ObiectJoc* dreapta = _joc->harta->iaObiect(rand, coloana + 1);
	ObiectJoc* jos = _joc->harta->iaObiect(rand + 1, coloana);
	ObiectJoc* stanga = _joc->harta->iaObiect(rand, coloana - 1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		if ((sus == nullptr || sus->tipObiect() != TIPURI_OBIECTE::perete) &&
			eInRaza(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2, 2 ,pos.x)) {
			_directieCurenta = DIR::sus;
			_destinatie = { coloana,rand - 1 };
			forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2, pos.y);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if ((dreapta == nullptr || dreapta->tipObiect() != TIPURI_OBIECTE::perete) &&
			eInRaza(_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2, 2, pos.y)) {
			_directieCurenta = DIR::dreapta;
			_destinatie = { coloana + 1,rand };
			forma().setPosition(pos.x, _joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		if ((jos == nullptr || jos->tipObiect() != TIPURI_OBIECTE::perete) &&
			eInRaza(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2, 2, pos.x)) {
			_directieCurenta = DIR::jos;
			_destinatie = { coloana,rand + 1 };
			forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2, pos.y);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if ((stanga == nullptr || stanga->tipObiect() != TIPURI_OBIECTE::perete) &&
			eInRaza(_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2, 2, pos.y)) {
			_directieCurenta = DIR::stanga;
			_destinatie = { coloana - 1,rand };
			forma().setPosition(pos.x, _joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
		}
	}

}

void Player::update() {
	input();
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

}