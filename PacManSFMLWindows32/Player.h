#pragma once
#include "ObiectJoc.h"
#include "Constante.h"
#include "Animatie.h"
class Player : public ObiectJoc {
private:
	DIR _directieCurenta = DIR::null;
	std::vector<const sf::Texture*> _texturi;
	float _distantaTraversataContor = 0;
	float _distantaTraversarePentruSchimbareTextura = 20.f;
	int _indexTextura = 0;
	sf::Vector2f _pozitieCurenta;
public:
	float _velocitate = 200.f;
	Player(Joc* joc);
	void miscare();
	void input();
	void update() override;
};