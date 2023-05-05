#include "Harta.h"
#include "Joc.h"
#include "Perete.h"

Harta::Harta(Joc* joc) : ObiectJoc(joc, new sf::CircleShape()), _tiledHarta("data\\harta.tmj") {
	_randuri = stoi(_tiledHarta.json()["height"].data);
	_coloane = stoi(_tiledHarta.json()["width"].data);
	auto marimeEcran = joc->ecran()->getSize();
	_lungime = marimeEcran.x / float(_coloane);
	_inaltime = marimeEcran.y / float(_randuri);
    for (int r = 0; r < _randuri; r++) {
        _matrice.push_back({});
        for (int c = 0; c < _coloane; c++) {
            int v = _tiledHarta.data[r * _coloane + c];
            if (v == 0) {
                _matrice[r].push_back(nullptr);
                continue;
            }
            v--;
            int texturaRand = v / 16;
            int texturaColoana = v % 16;
            const sf::Texture* textura = &joc->texturi.harta[texturaRand][texturaColoana];
            Perete* perete = new Perete(joc, textura);
            _matrice[r].push_back(perete);
            perete->forma().setPosition(c * _lungime, r * _inaltime);
            perete->forma().setScale(_lungime, _inaltime);
        }
    }
}

void Harta::update() {
    for (int r = 0; r < _randuri; r++) {
        for (int c = 0; c < _coloane; c++) {
            if (_matrice[r][c] == nullptr)continue;
            _matrice[r][c]->update();
        }
    }
}

void Harta::desenare() {
    for (int r = 0; r < _randuri; r++) {
        for (int c = 0; c < _coloane; c++) {
            if (_matrice[r][c] == nullptr)continue;
            _matrice[r][c]->desenare();
        }
    }
}

Harta::~Harta() {
    for (auto& rand : _matrice) {
        for (auto& v : rand) {
            if (v == nullptr)continue;
            delete v;
        }
    }
}