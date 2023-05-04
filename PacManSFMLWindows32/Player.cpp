#include "Player.h"
#include "Joc.h"
Player::Player(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({50,50})) {
	forma().setFillColor(sf::Color::Blue);
}

void Player::miscare() {
	if (_directieCurenta == DIR::sus) {
		forma().move(0, -5);
	}
	else if (_directieCurenta == DIR::dreapta) {
		forma().move(5, 0);
	}
	else if (_directieCurenta == DIR::jos) {
		forma().move(0, 5);
	}
	else if (_directieCurenta == DIR::stanga) {
		forma().move(-5, 0);
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
	else {
		_directieCurenta = DIR::null;
	}
}

void Player::update() {
	input();
	miscare();
}