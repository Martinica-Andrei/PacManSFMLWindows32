#pragma once
#include "Entitate.h"
#include "Animatie.h"
class Monstru : public Entitate{
private:
	Animatie _animatieSus;
	Animatie _animatieDreapta;
	Animatie _animatieJos;
	Animatie _animatieStanga;
	Animatie _animatieInfricosat1;
	Animatie _animatieInfricosat2;

	float _contorSecundePoarta = 0;
public:
	bool esteInfricosat;
	enum class TIP_MONSTRU {
		albastru=0,
		roz=1,
		galben=2,
		rosu=3
	};
	Monstru(Joc* joc, TIP_MONSTRU tipMonstru);

	void updateAnimatie();
	void update() override;
	void drumSprePlayer();
	void drumRandom();

	std::stack<DIR> drum;

	float secundePoarta = 3.f;

};