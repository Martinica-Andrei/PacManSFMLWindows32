#pragma once
#include <SFML/Graphics.hpp>
enum class TIPURI_OBIECTE {
	nimic=-1,
	perete = 0,
};
class Joc;
class Player;
class ObiectJoc {
private:
	sf::Shape* _forma; // pointer unic , fiecare obiect in parte are propria lui forma
protected:
	Joc* _joc;
public:
	bool eSters = false;
	virtual ~ObiectJoc() {
		delete _forma;
	}

	ObiectJoc(Joc* joc, sf::Shape* forma);

	sf::Shape& forma() {
		return *_forma;
	}

	virtual void desenare();
	virtual void update() {}
	virtual TIPURI_OBIECTE tipObiect() {
		return TIPURI_OBIECTE::nimic;
	}

	virtual void coliziune(Player& player){}
};

