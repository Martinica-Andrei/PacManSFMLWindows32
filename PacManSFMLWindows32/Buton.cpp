#include "Buton.h"
#include "Joc.h"
Buton::Buton(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })) {
	text.setFont(joc->font);
	iesire = [](Buton& buton) {
		buton.forma().setFillColor(sf::Color::White);
		buton.text.setFillColor(sf::Color::Black);
	};
	intrare = [](Buton& buton) {
		buton.forma().setFillColor(sf::Color(128, 128, 128));
		buton.text.setFillColor(sf::Color::White);
	};
	click = [](Buton& buton) {};
}

void Buton::update() {
	auto mousePos = sf::Mouse::getPosition(*_joc->ecran());

	if (forma().getGlobalBounds().contains(float(mousePos.x), float(mousePos.y))) {
		if (_esteIntrat == false) {
			intrare(*this);
			_esteIntrat = true;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			click(*this);
		}
	}
	else if (_esteIntrat) {
		iesire(*this);
		_esteIntrat = false;
	}
}
void Buton::desenare() {
	ObiectJoc::desenare();
	_joc->ecran()->draw(text);
}

void Buton::setarePozitie(float x, float y) {
	forma().setPosition(x, y);
	text.setPosition(x, y);
}

void Buton::centreazaText() {
	const auto& rectText = text.getGlobalBounds();
	const auto& rect = forma().getGlobalBounds();

	text.setPosition((rect.width - rectText.width) / 2 + rect.left, rect.top);
}