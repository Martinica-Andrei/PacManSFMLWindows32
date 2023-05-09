#include "Entitate.h"
#include "Joc.h"


Entitate::Entitate(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })), pos(forma().getPosition()),
scale(forma().getScale()) {

}


DIR Entitate::oprireMiscareDirectie() {
	int rand, coloana;
	auto& pos = forma().getPosition();
	if (_directieCurenta == DIR::sus) {
		rand = _joc->harta->iaRand(pos.y + _joc->harta->inaltimePeRand() / 2);
		coloana = _joc->harta->iaColoana(pos.x);
		if (rand == _destinatie.y && coloana == _destinatie.x) {
			forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2,
				_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
			return DIR::sus;
		}
	}
	else if (_directieCurenta == DIR::dreapta) {
		rand = _joc->harta->iaRand(pos.y);
		coloana = _joc->harta->iaColoana(pos.x - _joc->harta->lungimePeColoana() / 2);
		if (rand == _destinatie.y && coloana == _destinatie.x) {
			forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2,
				_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
			return DIR::dreapta;
		}
	}
	else if (_directieCurenta == DIR::jos) {
		rand = _joc->harta->iaRand(pos.y - _joc->harta->inaltimePeRand() / 2);
		coloana = _joc->harta->iaColoana(pos.x);
		if (rand == _destinatie.y && coloana == _destinatie.x) {
			forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2,
				_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
			return DIR::jos;
		}
	}
	else if (_directieCurenta == DIR::stanga) {
		rand = _joc->harta->iaRand(pos.y);
		coloana = _joc->harta->iaColoana(pos.x + _joc->harta->lungimePeColoana() / 2);
		if (rand == _destinatie.y && coloana == _destinatie.x) {
			forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2,
				_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
			return DIR::stanga;
		}
	}
	return DIR::null;
}

void Entitate::continuareMiscareDirectie(DIR oprireMiscare) {
	if (oprireMiscare == DIR::sus) {
		_destinatie.y--;
	}
	else if (oprireMiscare == DIR::dreapta) {
		_destinatie.x++;
	}
	else if (oprireMiscare == DIR::jos) {
		_destinatie.y++;
	}
	else if (oprireMiscare == DIR::stanga) {
		_destinatie.x--;
	}
}
void Entitate::miscare() {
	ObiectJoc* obiect = _joc->harta->iaObiect(_destinatie.y, _destinatie.x);
	if (obiect != nullptr && obiect->tipObiect() == TIPURI_OBIECTE::perete) return;
	float viteza = _velocitate * _joc->timpDeLaUltimulFrame;
	if (_directieCurenta == DIR::sus) {
		forma().move(0, -viteza);
	}
	if (_directieCurenta == DIR::dreapta) {
		forma().move(viteza, 0);
	}
	if (_directieCurenta == DIR::jos) {
		forma().move(0, viteza);
	}
	if (_directieCurenta == DIR::stanga) {
		forma().move(-viteza, 0);
	}
}
void Entitate::rotire() {
	if (_directieCurenta == DIR::sus) {
		forma().setRotation(270);

	}
	if (_directieCurenta == DIR::dreapta) {
		forma().setRotation(0);

	}
	if (_directieCurenta == DIR::jos) {
		forma().setRotation(90);

	}
	if (_directieCurenta == DIR::stanga) {
		forma().setRotation(180);

	}
}

void Entitate::setareDirectieCurenta(DIR directieCurenta) {
	_directieCurenta = directieCurenta;
	int rand = _joc->harta->iaRand(pos.y);
	int coloana = _joc->harta->iaColoana(pos.x);
	if (_directieCurenta == DIR::sus) {
		_destinatie = { coloana,rand - 1 };
		forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2, pos.y);
	}
	else if (_directieCurenta == DIR::dreapta) {
		_destinatie = { coloana + 1,rand };
		forma().setPosition(pos.x, _joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
	}
	else if (_directieCurenta == DIR::jos) {
		_destinatie = { coloana,rand + 1 };
		forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2, pos.y);
	}
	else if (_directieCurenta == DIR::stanga) {
		_destinatie = { coloana - 1,rand };
		forma().setPosition(pos.x, _joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
	}
	else {
		_destinatie = { coloana , rand };
	}
}