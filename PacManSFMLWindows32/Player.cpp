#include "Player.h"
#include "Joc.h"
#include <iostream>
Player::Player(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })),
_animatie(joc, { &joc->texturi.pacman_1, &joc->texturi.pacman_2 }, 25) {
	forma().setScale(40, 40);
	forma().setOrigin(0.5, 0.5);
	forma().setTexture(_animatie.texturaCurenta());
	forma().setRotation(270);
}

void Player::miscare() {
	_pozitieCurenta = forma().getPosition();
	float viteza = _velocitate * _joc->timpDeLaUltimulFrame;

	auto& pos = forma().getPosition();
	int rand = _joc->harta->iaRand(pos.y);
	int coloana = _joc->harta->iaColoana(pos.x);
	ObiectJoc* sus = _joc->harta->matrice[rand - 1][coloana];
	ObiectJoc* dreapta = _joc->harta->matrice[rand][coloana + 1];
	ObiectJoc* jos = _joc->harta->matrice[rand + 1][coloana];
	ObiectJoc* stanga = _joc->harta->matrice[rand][coloana - 1];

	if(eAjunsLaDestinatie){

		if (_directieCurenta == DIR::sus) {
			if (sus == nullptr || sus->tipObiect() != TIPURI_OBIECTE::perete) {
				eAjunsLaDestinatie = false;
				destinatie = pos.y - _joc->harta->inaltimePeRand();
			}
		}
		else if (_directieCurenta == DIR::dreapta) {
			if (dreapta == nullptr || dreapta->tipObiect() != TIPURI_OBIECTE::perete) {
				eAjunsLaDestinatie = false;
				destinatie = pos.x + _joc->harta->lungimePeColoana();
			}
		}
		else if (_directieCurenta == DIR::jos) {
			if (jos == nullptr || jos->tipObiect() != TIPURI_OBIECTE::perete) {
				eAjunsLaDestinatie = false;
				destinatie = pos.y + _joc->harta->inaltimePeRand();
			}
		}
		else if (_directieCurenta == DIR::stanga) {
			if (stanga == nullptr || stanga->tipObiect() != TIPURI_OBIECTE::perete) {
				eAjunsLaDestinatie = false;
				destinatie = pos.x - _joc->harta->lungimePeColoana();
			}
		}
	}
	if (eAjunsLaDestinatie == true) return;
	if (_directieCurenta == DIR::sus) {
		forma().move(0, -viteza);
		forma().setRotation(270);
		eAjunsLaDestinatie = destinatie > pos.y;
		if (eAjunsLaDestinatie) {
			forma().setPosition(pos.x, destinatie);
		}
	}
	else if (_directieCurenta == DIR::dreapta) {
		forma().move(viteza, 0);
		forma().setRotation(0);
		eAjunsLaDestinatie = destinatie < pos.x;
		if (eAjunsLaDestinatie) {
			forma().setPosition(destinatie, pos.y);
		}
	}
	else if (_directieCurenta == DIR::jos) {
		forma().move(0, viteza);
		forma().setRotation(90);
		eAjunsLaDestinatie = destinatie < pos.y;
		if (eAjunsLaDestinatie) {
			forma().setPosition(pos.x, destinatie);
		}
	}
	else if (_directieCurenta == DIR::stanga) {
		forma().move(-viteza, 0);
		forma().setRotation(180);
		eAjunsLaDestinatie = destinatie > pos.x;
		if (eAjunsLaDestinatie) {
			forma().setPosition(destinatie, pos.y);
		}
	}

}

void Player::input() {
	auto& pos = forma().getPosition();
	int rand = _joc->harta->iaRand(pos.y);
	int coloana = _joc->harta->iaColoana(pos.x);
	ObiectJoc* sus = _joc->harta->matrice[rand - 1][coloana];
	ObiectJoc* dreapta = _joc->harta->matrice[rand][coloana + 1];
	ObiectJoc* jos = _joc->harta->matrice[rand + 1][coloana];
	ObiectJoc* stanga = _joc->harta->matrice[rand][coloana - 1];

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && (sus == nullptr || sus->tipObiect() != TIPURI_OBIECTE::perete)) {
		_directieCurenta = DIR::sus;
		eAjunsLaDestinatie = false;
		destinatie = pos.y - _joc->harta->inaltimePeRand();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && (dreapta == nullptr || dreapta->tipObiect() != TIPURI_OBIECTE::perete)) {
		_directieCurenta = DIR::dreapta;
		eAjunsLaDestinatie = false;
		destinatie = pos.x + _joc->harta->lungimePeColoana();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && (jos == nullptr || jos->tipObiect() != TIPURI_OBIECTE::perete)) {
		_directieCurenta = DIR::jos;
		eAjunsLaDestinatie = false;
		destinatie = pos.y + _joc->harta->inaltimePeRand();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && (stanga == nullptr || stanga->tipObiect() != TIPURI_OBIECTE::perete)) {
		_directieCurenta = DIR::stanga;
		eAjunsLaDestinatie = false;
		destinatie = pos.x - _joc->harta->lungimePeColoana();
	}
}

void Player::update() {
	input();
	miscare();
	sf::Vector2f distantaTraversata = (_pozitieCurenta - forma().getPosition());
	_animatie.adaugareContor(abs(distantaTraversata.x) + abs(distantaTraversata.y));
	forma().setTexture(_animatie.texturaCurenta());
	
	auto t = forma().getPosition();
	std::cout << t.x << " " << destinatie << '\n';
}