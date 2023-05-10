#include "Harta.h"
#include "Joc.h"
#include "Perete.h"
#include "Mancare.h"
Harta::Harta(Joc* joc) : ObiectJoc(joc, new sf::CircleShape()), _tiledHarta("data\\harta.tmj") {
	_randuri = stoi(_tiledHarta.json()["height"].data);
	_coloane = stoi(_tiledHarta.json()["width"].data);
	auto marimeEcran = joc->ecran()->getSize();
	_lungimePeColoana = marimeEcran.x / float(_coloane);
	_inaltimePeRand = (marimeEcran.y - _startY - 45) / float(_randuri);
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
            ObiectJoc* obiect;
            if (v < 45) {
                Perete* perete = new Perete(joc, textura);
                _pereti.push_back(perete);
                perete->texturaRand = texturaRand;
                perete->texturaColoana = texturaColoana;
                obiect = perete;
            }
            else {
                bool areAbilitate = (v == 47);
                nrDeMancaruri++;
                obiect = new Mancare(joc, areAbilitate);
                obiect->forma().setTexture(textura);
            }
            if (v == 44) {
                obiect->tipObiect = TIPURI_OBIECTE::usa;
            }
            matrice[r].push_back(obiect);
            obiect->forma().setPosition(c * _lungimePeColoana, r * _inaltimePeRand + _startY);
            obiect->forma().setScale(_lungimePeColoana, _inaltimePeRand);
        }
    }

    _eventClipire.terminare();
    _eventClipire.secundePanaLaTerminare = 4;
    _eventClipireInterval.secundePanaLaTerminare = 0.4f;
    _eventClipireInterval.sfarsitEfect = [this]() {
        _indexClipire++;
        if (_indexClipire > 2) {
            _indexClipire = 0;
        }
        const std::vector<std::vector<sf::Texture>>* tipHarta = &_joc->texturi.harta;
        if (_indexClipire == 1) {
            tipHarta = &_joc->texturi.hartaClipire;
        }
        for (auto& perete : _pereti) {
            perete->forma().setTexture(&(*tipHarta)[perete->texturaRand][perete->texturaColoana]);
        }
        _eventClipireInterval.resetare();
    };
    _eventClipire.startEfect = [this]() {
        _joc->eFreeze = true;
    };
    _eventClipire.updateEfect = [this]() {
        _eventClipireInterval.update();
    };
    _eventClipire.sfarsitEfect = [this]() {     
        _joc->eFreeze = false;
        _joc->incepeNivelNou = true;
    };
}

void Harta::update() {
    if (nrDeMancaruri == 0 && _eventClipire.esteTerminat()) {
        _eventClipire.resetare();
        _eventClipire.update();
        return;
    }
    for (int r = 0; r < _randuri; r++) {
        for (int c = 0; c < _coloane;c++) {
            ObiectJoc* obiect = matrice[r][c];
            if (obiect == nullptr) {
                continue;
            }
            if (obiect->eSters) {
                delete obiect;
                matrice[r][c] = nullptr;
            }
            else {
                obiect->update();
            }
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


ObiectJoc* Harta::iaObiect(unsigned int rand, unsigned int coloana) {
    if (rand >= _randuri || coloana >= _coloane) {
        return nullptr;
    }
    return matrice[rand][coloana];
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

void Harta::coliziune(Player& player) {
    for (int r = 0; r < _randuri; r++) {
        for (int c = 0; c < _coloane; c++) {
            if (c == 6 && r == 23) {
                int debug = 1;
            }
            ObiectJoc* obiect = matrice[r][c];
            if (obiect) {
                obiect->coliziune(player);
            }
        }
    }
}

void Harta::updateCandEFreeze() {
    _eventClipire.update();
}