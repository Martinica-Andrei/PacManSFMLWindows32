#include "Joc.h"
#include "ObiectJoc.h"
#include "Player.h"
#include "Monstru.h"
Joc::Joc() {
    srand(time(0));
    font.loadFromFile("data\\fonts\\arial.ttf");
    _meniuPrincipal = new MeniuPrincipal(this);
    _meniuPrincipal->activeaza();
    _ecran->setFramerateLimit(frameratePeSecunda);
    
}
void Joc::adaugaMonstru(Monstru* monstru) {
    obiecte.push_back(monstru);
    monstrii.push_back(monstru);
}

void Joc::creareMonstrii() {
    Monstru* albastru = new Monstru(this, Monstru::TIP_MONSTRU::albastru);
    albastru->setareCoordonate(14, 14);
    Monstru* roz = new Monstru(this, Monstru::TIP_MONSTRU::roz);
    roz->setareCoordonate(14, 12);
    Monstru* galben = new Monstru(this, Monstru::TIP_MONSTRU::galben);
    galben->setareCoordonate(14, 16);
    Monstru* rosu = new Monstru(this, Monstru::TIP_MONSTRU::rosu);
    rosu->setareCoordonate(11, 12);
    adaugaMonstru(albastru);
    adaugaMonstru(roz);
    adaugaMonstru(galben);
    adaugaMonstru(rosu);
    albastru->secundePoarta = 2.f;
    roz->secundePoarta = 4.f;
    galben->secundePoarta = 6.f;
}

Joc::~Joc() {
    delete _ecran;
    sfarsit();
    delete _meniuPrincipal;
}
void Joc::init() {
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
    if (eGameOver) {
        sfarsit();
        _meniuPrincipal->activeaza();
    }
    if (_meniuPrincipal->esteActiv()) {
        _meniuPrincipal->update();
    }
    else {
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

}
void Joc::desenare() {
    _ecran->clear();
    if (_meniuPrincipal->esteActiv()) {
        _meniuPrincipal->desenare();
    }
    else {
        for (int i = 0; i < obiecte.size(); i++) {
            obiecte[i]->desenare();
        }
    }
    _ecran->display();
}


void Joc::start() {
    eGameOver = false;
    _meniuPrincipal->dezactiveaza();
    harta = new Harta(this);
    obiecte.push_back(harta);
    player = new Player(this);
    player->hotarXStanga = -player->scale.x / 2;
    player->hotarXDreapta = _ecran->getSize().x + player->scale.x / 2;
    obiecte.push_back(player);
    creareMonstrii();
}
void Joc::sfarsit() {
    for (auto& obiect : obiecte) {
        delete obiect;
    }
    obiecte.clear();
    monstrii.clear();

}
void Joc::resetare() {
    sfarsit();
    start();
}