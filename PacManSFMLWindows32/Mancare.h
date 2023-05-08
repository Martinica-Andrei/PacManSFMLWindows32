#pragma once
#include "ObiectJoc.h"
class Mancare : public ObiectJoc {
private:
public:

	Mancare(Joc* joc);

	void coliziune(Player& player) override;
};