#include "CutieColiziune.h"
#include "Joc.h"
CutieColiziune::CutieColiziune(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({1,1})) {
	forma().setTexture(&joc->texturi.cutieColiziune);
	forma().setFillColor(sf::Color::Red);
}