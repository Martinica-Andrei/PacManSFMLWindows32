#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
class Texturi {
private:
	std::vector<std::vector<sf::Texture>> incarcareAtlas(const std::string& numeFisier, int randuri, int coloane, int lungime, int inaltime, int spatiu);

public:

	sf::Texture pacman_1;
	sf::Texture pacman_2;
	sf::Texture cutieColiziune;
	sf::Texture background;
	std::vector<std::vector<sf::Texture>> harta;

	Texturi();

};