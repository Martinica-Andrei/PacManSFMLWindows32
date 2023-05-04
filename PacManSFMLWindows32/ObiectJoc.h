#pragma once

#include <SFML/Graphics.hpp>
class Joc;
class ObiectJoc {
private:
	Joc* _joc;
	sf::Shape* _forma; // pointer unic , fiecare obiect in parte are propria lui forma
public:

	virtual ~ObiectJoc() {
		delete _forma;
	}

	ObiectJoc(Joc* joc, sf::Shape* forma);

	sf::Shape& forma() {
		return *_forma;
	}

	void desenare();
	
	virtual void update() {}
};