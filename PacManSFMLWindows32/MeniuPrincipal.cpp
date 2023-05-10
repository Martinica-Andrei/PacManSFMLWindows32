#include "MeniuPrincipal.h"
#include "Joc.h"

MeniuPrincipal::MeniuPrincipal(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })) {
	const auto& marimeEcran = _joc->ecran()->getSize();
	_numeJoc = sf::Text("PAC-MAN", _joc->font, 80);
	_numeJoc.setPosition((marimeEcran.x - _numeJoc.getGlobalBounds().width) / 2, 100);

	_butonJoaca = new Buton(joc);
	_butonJoaca->setarePozitie(300, 300);
	_butonJoaca->forma().setScale(200, 50);
	_butonJoaca->text.setString("Joaca");
	_butonJoaca->text.setFillColor(sf::Color::Black);
	_butonJoaca->centreazaText();

	// expresie lambda, [] e capture list , adica ce variabile poate accesa in plus in functie
	// aici este this adica acest obiect
	// trebuie folosit obiectul std::function  pentru a putea stoca functia cand are capture list
	// nu se poate folosi un pointer simplu de felul void (*)(Buton&) cu capture list
	_butonJoaca->click = [this](Buton& buton) {
		_joc->start();
	};
}

void MeniuPrincipal::desenare() {
	_joc->ecran()->draw(_numeJoc);
	_butonJoaca->desenare();
}

MeniuPrincipal::~MeniuPrincipal() {
	delete _butonJoaca;
}

void MeniuPrincipal::update() {
	_butonJoaca->update();
}

