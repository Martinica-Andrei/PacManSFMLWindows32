#pragma once
#include <SFML/Graphics.hpp>
class Joc;
class ObiectJoc {
private:
	sf::Shape* _forma; // pointer unic , fiecare obiect in parte are propria lui forma
protected:
	Joc* _joc;
public:

	virtual ~ObiectJoc() {
		delete _forma;
	}

	ObiectJoc(Joc* joc, sf::Shape* forma);

	sf::Shape& forma() {
		return *_forma;
	}

	virtual void desenare();
	
	virtual void update() {}

};