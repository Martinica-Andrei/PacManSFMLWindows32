#include "Joc.h"
#include "ObiectJoc.h"
#include "Player.h"
#include "Monstru.h"
Joc::Joc() {
    srand(time(0));
    _ecran->setFramerateLimit(frameratePeSecunda);
    harta = new Harta(this);
    obiecte.push_back(harta);
    player = new Player(this);
    obiecte.push_back(player);
    Monstru* albastru = new Monstru(this, Monstru::TIP_MONSTRU::albastru);
    albastru->setareCoordonate(14, 14);
    Monstru* roz = new Monstru(this, Monstru::TIP_MONSTRU::roz);
    roz->setareCoordonate(14, 12);
    Monstru* galben = new Monstru(this, Monstru::TIP_MONSTRU::galben);
    galben->setareCoordonate(14, 16);
    Monstru* rosu = new Monstru(this, Monstru::TIP_MONSTRU::rosu);
    rosu->setareCoordonate(11, 12);
    obiecte.push_back(albastru);
    albastru->secundePoarta = 2.f;
    obiecte.push_back(roz);
    roz->secundePoarta = 4.f;
    obiecte.push_back(galben);
    galben->secundePoarta = 6.f;
    obiecte.push_back(rosu);
    
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