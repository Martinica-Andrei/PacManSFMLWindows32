#pragma once
#include "ObiectJoc.h"
class Buton;
using FunctieButon = void (*)(Buton&);

class Buton : public ObiectJoc {
private:
	bool _esteIntrat = false;
public:
	FunctieButon click = nullptr;
	FunctieButon intrare = nullptr;
	FunctieButon iesire = nullptr;
	sf::Text text;
	Buton(Joc* joc);

	void update()override;
	void desenare() override;

	void setarePozitie(float x, float y);
	void centreazaText();
};