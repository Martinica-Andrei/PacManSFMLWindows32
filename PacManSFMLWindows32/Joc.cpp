#include "Joc.h"
#include "ObiectJoc.h"
#include "Player.h"
#include "Tiled.h"
#include "Perete.h"
Joc::Joc() {
    _ecran->setFramerateLimit(frameratePeSecunda);
    player = new Player(this);
    obiecte.push_back(player);
    Tiled harta("data\\harta.tmj");
    int inaltime = stoi(harta.json()["height"].data);
    int lungime = stoi(harta.json()["width"].data);
    int marimePixel = 25;
    for (int r = 0; r < inaltime; r++) {
        for (int c = 0; c < lungime; c++) {
            int v = harta.data[r * lungime + c];
            if (v == 0) {
                continue;
            }
            v--;
            int texturaRand = v / 16;
            int texturaColoana = v % 16;
            const sf::Texture* textura = &texturi.harta[texturaRand][texturaColoana];
            Perete* perete = new Perete(this, textura);
            obiecte.push_back(perete);
            perete->forma().setPosition(c * 28.57, r * 25.8);
            perete->forma().setScale(28.57, 25.8);
        }
    }
}

Joc::~Joc() {
    delete _ecran;
    for (auto& obiect : obiecte) {
        delete obiect;
    }
}
void Joc::start() {
    sf::Clock ceas;
    while (_ecran->isOpen())
    {
        sf::Event event;
        while (_ecran->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _ecran->close();
        }
        float timpDeLaUltimulFrameTotal = ceas.restart().asSeconds();
        // sa zicem ca jocul da freeze si trece o secunda, daca nu facem acest loop
        // atunci oricare obiect care se misca folosind timpul, se va teleporta fara a verifica coliziuni
        while (timpDeLaUltimulFrameTotal >= 0) {
            if (timpDeLaUltimulFrameTotal <= _milisecundePeFrame) {
                timpDeLaUltimulFrame = timpDeLaUltimulFrameTotal;
                timpDeLaUltimulFrameTotal = -1;
            }
            else {
                timpDeLaUltimulFrameTotal -= _milisecundePeFrame;
                timpDeLaUltimulFrame = _milisecundePeFrame;
            }
            update();
        }
        desenare();
    }
}
void Joc::update() {
    for (int i = 0; i < obiecte.size(); i++) {
        obiecte[i]->update();
    }


}
void Joc::desenare() {
    _ecran->clear();
    for (int i = 0; i < obiecte.size(); i++) {
        obiecte[i]->desenare();
    }
    _ecran->display();
}