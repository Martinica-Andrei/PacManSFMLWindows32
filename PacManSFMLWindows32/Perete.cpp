#include "Perete.h"

Perete::Perete(Joc* joc, const sf::Texture* textura) : ObiectJoc(joc, new sf::RectangleShape({1,1})) {
	forma().setTexture(textura);
	tipObiect = TIPURI_OBIECTE::perete;
}