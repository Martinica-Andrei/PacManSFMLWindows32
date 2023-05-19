#pragma once
#include <functional>
#include "ObiectJoc.h"

class Buton : public ObiectJoc {
private:
	bool _esteIntrat = false;
public:
	std::function<void(Buton&)> click;
	std::function<void(Buton&)> intrare;
	std::function<void(Buton&)> iesire;
	sf::Text text;
	Buton(Joc* joc);

	void update()override;
	void desenare() override;

	void setarePozitie(float x, float y);
	void centreazaText();
};