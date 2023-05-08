#pragma once
#include "Entitate.h"
#include "Animatie.h"
class Monstru : public Entitate{
private:
	Animatie _animatieSus;
	Animatie _animatieDreapta;
	Animatie _animatieJos;
	Animatie _animatieStanga;
public:

	Monstru(Joc* joc);
};