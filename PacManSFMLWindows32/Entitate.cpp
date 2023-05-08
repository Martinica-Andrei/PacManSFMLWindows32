#include "Entitate.h"
#include "Joc.h"


Entitate::Entitate(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })), pos(forma().getPosition()),
scale(forma().getScale()) {

}

void Entitate::miscare() {
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

	auto& pos = forma().getPosition();
	if (_directieCurenta == DIR::sus) {
		_rand = _joc->harta->iaRand(pos.y + _joc->harta->inaltimePeRand() / 2);
		_coloana = _joc->harta->iaColoana(pos.x);
		if (_rand == _destinatie.y && _coloana == _destinatie.x) {
			_destinatie.y--;
		}
	}
	else if (_directieCurenta == DIR::dreapta) {
		_rand = _joc->harta->iaRand(pos.y);
		_coloana = _joc->harta->iaColoana(pos.x - _joc->harta->lungimePeColoana() / 2);
		if (_rand == _destinatie.y && _coloana == _destinatie.x) {
			_destinatie.x++;
		}
	}
	else if (_directieCurenta == DIR::jos) {
		_rand = _joc->harta->iaRand(pos.y - _joc->harta->inaltimePeRand() / 2);
		_coloana = _joc->harta->iaColoana(pos.x);
		if (_rand == _destinatie.y && _coloana == _destinatie.x) {
			_destinatie.y++;
		}
	}
	else if (_directieCurenta == DIR::stanga) {
		_rand = _joc->harta->iaRand(pos.y);
		_coloana = _joc->harta->iaColoana(pos.x + _joc->harta->lungimePeColoana() / 2);
		if (_rand == _destinatie.y && _coloana == _destinatie.x) {
			_destinatie.x--;
		}
	}
}