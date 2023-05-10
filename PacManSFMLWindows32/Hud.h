#pragma once
#include "ObiectJoc.h"

class Hud : public ObiectJoc {
private:
	sf::Text _textScor;
	std::vector<ObiectJoc*> _vieti;
	int _scor = 0;
public:

	Hud(Joc* joc);
	~Hud();

	void adaugareScor(int val);

	void desenare() override;
	void resetare();
	int vieti() {
		return _vieti.size();
	}

	void decrementareViata() {
		if (_vieti.size()) {
			delete _vieti.back();
			_vieti.pop_back();
		}
	}
};