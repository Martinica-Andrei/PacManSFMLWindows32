#include "Entitate.h"
#include "Joc.h"


Entitate::Entitate(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })), pos(forma().getPosition()),
scale(forma().getScale()) {

}
