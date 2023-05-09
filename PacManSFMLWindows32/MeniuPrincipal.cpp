#include "MeniuPrincipal.h"
#include "Joc.h"
MeniuPrincipal::MeniuPrincipal(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })) {
	const auto& marimeEcran = _joc->ecran()->getSize();
	_numeJoc = sf::Text("PAC-MAN", _joc->font, 80);
	_numeJoc.setPosition((marimeEcran.x - _numeJoc.getGlobalBounds().width) / 2, 100);

	_butonJoaca = new Buton(joc);
	_butonJoaca->setarePozitie(300, 300);
	_butonJoaca->forma().setScale(200, 50);
	_butonJoaca->text.setString("test");
	_butonJoaca->text.setFillColor(sf::Color::Black);
	_butonJoaca->centreazaText();
	_butonJoaca->click = [](Buton& buton) {
		std::cout << "BUTON APASAT";
	};
	_butonJoaca->iesire = [](Buton& buton) {
		std::cout << "BUTON IESIRE";
	};
	_butonJoaca->intrare = [](Buton& buton) {
		std::cout << "BUTON INTRARE";
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