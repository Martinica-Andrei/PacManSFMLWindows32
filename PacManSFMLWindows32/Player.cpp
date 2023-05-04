#include "Player.h"
#include "Joc.h"
#include <iostream>
Player::Player(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })),
_animatie(joc, { &joc->texturi.pacman_1, &joc->texturi.pacman_2 }, 25) {
	forma().setScale(40, 40);
	forma().setOrigin(0.5, 0.5);
	forma().move(25, 25);
	forma().setTexture(_animatie.texturaCurenta());
}

void Player::miscare() {
	_pozitieCurenta = forma().getPosition();
	float viteza = _velocitate * _joc->timpDeLaUltimulFrame;

	if (_directieCurenta == DIR::sus) {
		forma().move(0, -viteza);
		forma().setRotation(270);
	}
	else if (_directieCurenta == DIR::dreapta) {
		forma().move(viteza, 0);
		forma().setRotation(0);
	}
	else if (_directieCurenta == DIR::jos) {
		forma().move(0, viteza);
		forma().setRotation(90);
	}
	else if (_directieCurenta == DIR::stanga) {
		forma().move(-viteza, 0);
		forma().setRotation(180);
	}
}

void Player::input() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		_directieCurenta = DIR::sus;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		_directieCurenta = DIR::dreapta;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		_directieCurenta = DIR::jos;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		_directieCurenta = DIR::stanga;
	}
}

void Player::update() {
	input();
	miscare();
	sf::Vector2f distantaTraversata = (_pozitieCurenta - forma().getPosition());
	_animatie.adaugareContor(abs(distantaTraversata.x) + abs(distantaTraversata.y));
	forma().setTexture(_animatie.texturaCurenta());
}