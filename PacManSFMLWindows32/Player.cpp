#include <iostream>
#include "Player.h"
#include "Joc.h"
#include "Monstru.h"
Player::Player(Joc* joc) : Entitate(joc),
_animatie(joc, { &joc->texturi.pacman_1, &joc->texturi.pacman_2 }, 10) {
	auto marimeEcran = _joc->ecran()->getSize();
	forma().setScale(30.f * marimeEcran.x / 800, 30.f * marimeEcran.y / 600);
	forma().setOrigin(0.5, 0.5);
	forma().setTexture(_animatie.texturaCurenta());
	forma().setRotation(270);
	forma().setPosition(joc->harta->iaCoordonataColoana(14) + joc->harta->lungimePeColoana() / 2,
		joc->harta->iaCoordonataRand(23) + joc->harta->inaltimePeRand() / 2);
	_velocitate = 150.f;

	_textScorMancatMonstru.setFont(joc->font);
	_textScorMancatMonstru.setCharacterSize(25);
	_textScorMancatMonstru.setFillColor(sf::Color::Blue);

	_eventOprireTimp.terminare();
	_eventOprireTimp.secundePanaLaTerminare = 1;
	_eventOprireTimp.startEfect = [this]() {
		_joc->eFreeze = true;
		forma().setFillColor({ 255, 255, 255, 0 });
		_monstruMancat->forma().setFillColor({ 255, 255, 255, 0 });
		_textScorMancatMonstru.setFillColor({ 255, 255, 255, 255 });
		_textScorMancatMonstru.setPosition(_monstruMancat->pos.x - _monstruMancat->scale.x, _monstruMancat->pos.y - _monstruMancat->scale.y);
		_textScorMancatMonstru.setString(std::to_string(_mancatCombo));
	};
	_eventOprireTimp.sfarsitEfect = [this]() {
		forma().setFillColor({ 255, 255, 255, 255 });
		_monstruMancat->forma().setFillColor({ 255, 255, 255, 255 });
		_textScorMancatMonstru.setFillColor({ 255, 255, 255, 0 });
		_joc->eFreeze = false;
		_monstruMancat = nullptr;
	};
	_eventGameOver.terminare();
	_eventGameOver.secundePanaLaTerminare = 2;
	_eventGameOver.startEfect = [this]() {
		_joc->eFreeze = true;
		for (auto& monstru : _joc->monstrii) {
			monstru->forma().setFillColor({255, 255, 255, 0});
		}
	};
	_eventGameOver.updateEfect = [this]() {
		forma().rotate(360 * _joc->timpDeLaUltimulFrame);
		forma().setScale(scale.x - 10 * _joc->timpDeLaUltimulFrame, scale.y - 10 * _joc->timpDeLaUltimulFrame);
	};
	_eventGameOver.sfarsitEfect = [this]() {
		_joc->eFreeze = false;
		_joc->eGameOver = true;
	};

	hotarXStanga = -scale.x / 2;
	hotarXDreapta = joc->ecran()->getSize().x + scale.x / 2;
}
void Player::rulareEventGameOver() {
	_eventGameOver.resetare();
	_eventGameOver.update();
}

void Player::desenare() {
	ObiectJoc::desenare();
	_joc->ecran()->draw(_textScorMancatMonstru);
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
	auto rect = forma().getGlobalBounds();
	for (auto& monstru : _joc->monstrii) {
		monstru->coliziune(*this);
	}

	if (_abilitateImunitate) {
		_abilitateImunitate->update();
		if (_abilitateImunitate->esteTerminat()) {
			delete _abilitateImunitate;
			_abilitateImunitate = nullptr;
		}
	}
	hotare();

}

void Player::adaugareAbilitateImunitate() {
	if (_abilitateImunitate) {
		delete _abilitateImunitate;
	}
	_abilitateImunitate = new AbilitateImunitate(_joc);
	_mancatCombo = 200;
}

Player::~Player() {
	delete _abilitateImunitate;
}

void Player::manancaMonstru(Monstru* monstru) {
	if (poateMancaMonstru() == false) return;
	monstru->respawn();
	_monstruMancat = monstru;
	_eventOprireTimp.resetare();
	_eventOprireTimp.update();
	_joc->hud->adaugareScor(_mancatCombo);
	_mancatCombo *= 2;
}

void Player::updateCandEFreeze() {
	_eventOprireTimp.update();
	_eventGameOver.update();
}