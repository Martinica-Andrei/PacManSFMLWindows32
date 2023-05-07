#include "Harta.h"
#include "Joc.h"
#include "Perete.h"

Harta::Harta(Joc* joc) : ObiectJoc(joc, new sf::CircleShape()), _tiledHarta("data\\harta.tmj") {
	_randuri = stoi(_tiledHarta.json()["height"].data);
	_coloane = stoi(_tiledHarta.json()["width"].data);
	auto marimeEcran = joc->ecran()->getSize();
	_lungimePeColoana = marimeEcran.x / float(_coloane);
	_inaltimePeRand = marimeEcran.y / float(_randuri);
    for (int r = 0; r < _randuri; r++) {
        matrice.push_back({});
        for (int c = 0; c < _coloane; c++) {
            int v = _tiledHarta.data[r * _coloane + c];
            if (v == 0) {
                matrice[r].push_back(nullptr);
                continue;
            }
            v--;
            int texturaRand = v / 16;
            int texturaColoana = v % 16;
            const sf::Texture* textura = &joc->texturi.harta[texturaRand][texturaColoana];
            Perete* perete = new Perete(joc, textura);
            matrice[r].push_back(perete);
            perete->forma().setPosition(c * _lungimePeColoana, r * _inaltimePeRand);
            perete->forma().setScale(_lungimePeColoana, _inaltimePeRand);
        }
    }
}

void Harta::update() {
    for (int r = 0; r < _randuri; r++) {
        for (int c = 0; c < _coloane; c++) {
            if (matrice[r][c] == nullptr)continue;
            matrice[r][c]->update();
        }
    }
}

void Harta::desenare() {
    for (int r = 0; r < _randuri; r++) {
        for (int c = 0; c < _coloane; c++) {
            if (matrice[r][c] == nullptr)continue;
            matrice[r][c]->desenare();
        }
    }
}

Harta::~Harta() {
    for (auto& rand : matrice) {
        for (auto& v : rand) {
            if (v == nullptr)continue;
            delete v;
        }
    }
}



ObiectJoc* Harta::iaObiect(float x, float y) {
    return matrice[iaRand(y)][iaColoana(x)];
}

std::vector<ObiectJoc*> Harta::iaArieUnu(float x, float y) {
    std::vector<ObiectJoc*> raspuns;
    int rand = iaRand(y);
    int coloana  = iaColoana(x);
    // centru
    raspuns.push_back(matrice[rand][coloana]);
    // sus
    raspuns.push_back(matrice[rand - 1][coloana]);
    // dreapta
    raspuns.push_back(matrice[rand][coloana + 1]);
    // jos
    raspuns.push_back(matrice[rand + 1][coloana]);
    // stanga
    raspuns.push_back(matrice[rand][coloana - 1]);
    return raspuns;
}