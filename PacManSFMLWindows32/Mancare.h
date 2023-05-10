#pragma once
#include "ObiectJoc.h"
// pentru ca sunt doar doua mancaruri
// nu voi face mosteniri si pun doar o bool pentru putere
class Mancare : public ObiectJoc {
private:
	bool _areAbilitate;
public:

	Mancare(Joc* joc, bool areAbilitate);

	void coliziune(Player& player) override;
};