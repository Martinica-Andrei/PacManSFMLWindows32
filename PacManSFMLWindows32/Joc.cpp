#include "Joc.h"
#include "ObiectJoc.h"
Joc::Joc() {
    _ecran->setFramerateLimit(75);
}
ObiectJoc* test;
void Joc::start() {
    test = new ObiectJoc(this, new sf::RectangleShape({ 100, 100 }));
    test->forma().setFillColor(sf::Color::Blue);
    test->forma().setPosition(300, 200);

    while (_ecran->isOpen())
    {
        sf::Event event;
        while (_ecran->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _ecran->close();
        }
        update();
        desenare();
    }
}

void Joc::update() {

}
void Joc::desenare() {
    _ecran->clear();
    test->desenare();
    _ecran->display();
}