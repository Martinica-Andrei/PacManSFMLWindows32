#include <queue>
#include "Entitate.h"
#include "Joc.h"

Entitate::Entitate(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })), pos(forma().getPosition()),
scale(forma().getScale()) {

}


DIR Entitate::oprireMiscareDirectie() {
	int rand, coloana;
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
	if (obiect != nullptr && peretiColiziune.count(obiect->tipObiect)) return;
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

void Entitate::setareCoordonate(int rand, int coloana) {
	forma().setPosition(_joc->harta->iaCoordonataColoana(coloana) + _joc->harta->lungimePeColoana() / 2,
		_joc->harta->iaCoordonataRand(rand) + _joc->harta->inaltimePeRand() / 2);
}
struct Vecini {
							  // sus      dreapta  stanga   jos
	std::vector<Vecini*> vecini{ nullptr, nullptr, nullptr, nullptr };
	sf::Vector2i pozitie;
	int index;

	~Vecini() {
		int i;
		// mai intai facem toti vecinii sai sa nu aiba referinte pe el insusi
		for (i = 0; i < vecini.size(); i++) {
			Vecini* vecin = vecini[i];
			if (vecin == nullptr) {
				continue;
			}
			vecin->vecini[3 - i] = nullptr;
		}
		// dupa aceea ii stergem
		for (auto& vecin : vecini) {
			delete vecin;
		}
	}

	Vecini(int index, sf::Vector2i pozitie) : index(index), pozitie(pozitie) {}

	int celMaiMicIndexDintreVecini() {
		int i, j = INT_MAX;
		int indexRaspuns = 0;
		for (i = 0; i < vecini.size(); i++) {
			Vecini* vecin = vecini[i];
			if (vecin && vecin->index < j) {
				j = vecin->index;
				indexRaspuns = i;
			}
		}
		return indexRaspuns;
	}
};

sf::Vector2i Entitate::coordonateMatrice() {
	return { _joc->harta->iaColoana(pos.x), _joc->harta->iaRand(pos.y) };
}

std::stack<DIR> Entitate::drumCatreCoordonate(int rand, int coloana) {
	stack<DIR> directii;
	int randThis = _joc->harta->iaRand(pos.y);
	int coloanaThis = _joc->harta->iaColoana(pos.x);
	std::vector<std::vector<bool>> visitate(_joc->harta->randuri(), std::vector<bool>(_joc->harta->coloane()));
	queue<Vecini*> coada;
	Vecini* cap = new Vecini(0, { coloanaThis, randThis });
	coada.push(cap);
	Vecini* curent;
	while (coada.size()) {
		curent = coada.front();
		auto& coord = curent->pozitie;
		if (coord.x < 0 || coord.x >= _joc->harta->coloane() || coord.y < 0 || coord.y >= _joc->harta->randuri()) {
			coada.pop();
			continue;
		}
		if (coord.x == coloana && coord.y == rand) {
			break;
		}
		if (visitate[coord.y][coord.x] == false) {
			visitate[coord.y][coord.x] = true;
			std::vector<sf::Vector2i> pozitii{
				{ coord.x, coord.y - 1 }, // sus
				{ coord.x + 1, coord.y }, // dreapta
				{ coord.x - 1, coord.y }, // stanga
				{ coord.x, coord.y + 1 } // jos
			};
			for (int i = 0; i < pozitii.size(); i++) {
				if (curent->vecini[i]) continue;
				sf::Vector2i& pozitieObiect = pozitii[i];
				ObiectJoc* obiect = _joc->harta->iaObiect(pozitieObiect.y, pozitieObiect.x);
				if (obiect == nullptr || peretiColiziune.count(obiect->tipObiect) == false) {
					Vecini* vecinNou = new Vecini(curent->index + 1, pozitieObiect);
					curent->vecini[i] = vecinNou;
					vecinNou->vecini[3 - i] = curent;
					coada.push(vecinNou);
				}
			}
	
		}
		coada.pop();
	}
	if (coada.size() > 1) {
		// curent e deja setat dar 100% sa nu fie erori
		curent = coada.front();
		do{
			int directie = curent->celMaiMicIndexDintreVecini();
			directii.push(DIR(3 - directie));
			curent = curent->vecini[directie];
	
		} while (curent && curent->index > 0);

	}
	delete cap;
	return directii;
}

void Entitate::hotare() {
	if (pos.x < hotarXStanga) {
		forma().setPosition(hotarXDreapta, pos.y);
		setareDirectieCurenta(directieCurenta());
	}
	else if (pos.x > hotarXDreapta) {
		forma().setPosition(hotarXStanga, pos.y);
		setareDirectieCurenta(directieCurenta());
	}
}