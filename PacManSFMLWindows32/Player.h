#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
#include "Animatie.h"
#include "Entitate.h"
#include "EventTimp.h"
#include "AbilitateImunitate.h"
class Player : public Entitate {
private:
	Animatie _animatie;
	sf::Vector2f _pozitieCurenta;

	AbilitateImunitate* _abilitateImunitate = nullptr;
	EventTimp _eventOprireTimp {_joc};
	EventTimp _eventGameOver{ _joc };
	sf::Text _textScorMancatMonstru;
	int _mancatCombo = 200;
	Monstru* _monstruMancat = nullptr;
public:
	void rulareEventGameOver();
	Player(Joc* joc);
	~Player();
	void miscare();
	void input();
	void update() override;
	void updateCandEFreeze() override;

	void adaugareAbilitateImunitate();

	void manancaMonstru(Monstru* monstru);
	bool poateMancaMonstru() {
		return (_monstruMancat == nullptr);
	}

	void desenare() override;
};