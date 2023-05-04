#include "Joc.h"
#include "ObiectJoc.h"
#include "Player.h"
Joc::Joc() {
    _ecran->setFramerateLimit(frameratePeSecunda);
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
        timpDeLaUltimulFrame = ceas.restart().asSeconds();
        update();
        desenare();
    }
}
#include <iostream>
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