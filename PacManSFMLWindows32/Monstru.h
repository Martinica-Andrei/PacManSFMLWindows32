#pragma once
#include "Entitate.h"
#include "Animatie.h"
class Monstru : public Entitate{
private:
	Animatie _animatieSus;
	Animatie _animatieDreapta;
	Animatie _animatieJos;
	Animatie _animatieStanga;
	std::vector<Animatie> _animatiiInfricosat;
	int _animatiiInfricosatIndex;
	float _contorSecundePoarta = 0;
	bool _esteInfricosat = false;
	bool _esteRespawn = false;

	float _velocitateNormala = 100.f;
	float _velocitateInfricosat = 75.f;
	float _velocitateRespawn = 300.f;
public:
	void incrementareAnimatiiInfricosatIndex();
	void setareAnimatiiInfricosatIndex(int val);
	enum class TIP_MONSTRU {
		albastru=0,
		roz=1,
		galben=2,
		rosu=3
	};
	Monstru(Joc* joc, TIP_MONSTRU tipMonstru);

	void updateAnimatie();
	void updateAnimatieNormal();
	void updateAnimatieInfricosat();
	void updateAnimatieOchi();
	void update() override;
	void drumSprePlayer();
	void drumRandom();

	std::stack<DIR> drum;

	float secundePoarta = 3.f;

	void coliziune(Player& player) override;

	bool esteInfricosat() {
		return _esteInfricosat;
	}

	void activareInfricosare();
	void dezactivareInfricosare();
	void respawn();
};