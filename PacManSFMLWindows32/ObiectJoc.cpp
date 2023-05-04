#include "ObiectJoc.h"
#include "Joc.h"

ObiectJoc::ObiectJoc(Joc* joc, sf::Shape* forma) : _joc(joc), _forma(forma) {

}

void ObiectJoc::desenare() {
	_joc->ecran()->draw(*_forma);
}