#pragma once
#include "ObiectJoc.h"
class Perete : public ObiectJoc {
private:
public:
	Perete(Joc* joc, const sf::Texture* textura);

	TIPURI_OBIECTE tipObiect() override {
		return TIPURI_OBIECTE::perete;
	}
};