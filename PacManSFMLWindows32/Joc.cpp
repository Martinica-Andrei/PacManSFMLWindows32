#include "Joc.h"
#include "ObiectJoc.h"
#include "Player.h"

Joc::Joc() {
    _ecran->setFramerateLimit(frameratePeSecunda);
 /*   const auto& ecranMarime = _ecran->getSize();
    ObiectJoc* background = new ObiectJoc(this, new sf::RectangleShape({ 1,1 }));
    background->forma().setScale(ecranMarime.x, ecranMarime.y);
    background->forma().setTexture(&texturi.background);
    obiecte.push_back(background);*/
    harta = new Harta(this);
    obiecte.push_back(harta);
    player = new Player(this);
    obiecte.push_back(player);
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
    for (int i = 0; i < obiecte.size();) {
        ObiectJoc* obiect = obiecte[i];
        if (obiect->eSters == true) {
            delete obiect;
            obiecte.erase(obiecte.begin() + i);
        }
        else {
            obiect->update();
            i++;
        }
    }

}
void Joc::desenare() {
    _ecran->clear();
    for (int i = 0; i < obiecte.size(); i++) {
        obiecte[i]->desenare();
    }
    _ecran->display();
}