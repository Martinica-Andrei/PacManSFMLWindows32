#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
class Texturi {
private:
	std::vector<std::vector<sf::Texture>> incarcareAtlas(const std::string& numeFisier, int randuri, int coloane, int lungime, int inaltime, int spatiu);

public:

	sf::Texture pacman_1;
	sf::Texture pacman_2;
	sf::Texture cutieColiziune;
	sf::Texture background;
	std::vector<std::vector<sf::Texture>> harta;
	std::vector<std::vector<sf::Texture>> hartaClipire;
	std::vector<std::vector<sf::Texture>> monstruRosu;
	std::vector<std::vector<sf::Texture>> monstruRoz;
	std::vector<std::vector<sf::Texture>> monstruAlbastru;
	std::vector<std::vector<sf::Texture>> monstruGalben;
	std::vector<std::vector<sf::Texture>> monstruInfricosat;
	std::vector<std::vector<sf::Texture>> monstruOchi;
	Texturi();

};