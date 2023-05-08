#include "Texturi.h"

Texturi::Texturi() {
	pacman_1.loadFromFile("data\\pacman_1.png");
	pacman_2.loadFromFile("data\\pacman_2.png");
	cutieColiziune.loadFromFile("data\\debug\\cutie_coliziune.png");
	background.loadFromFile("data\\background.png");
	harta = incarcareAtlas("data\\harta.png", 3, 16, 8, 8, 1);
}

std::vector<std::vector<sf::Texture>> Texturi::incarcareAtlas(const std::string& numeFisier, int randuri, int coloane, int lungime, int inaltime, int spatiu){
	int r, c;
	std::vector<std::vector<sf::Texture>> atlas(randuri, std::vector <sf::Texture>(coloane));
	for (r = 0; r < randuri; r++) {
		for (c = 0; c < coloane; c++) {
			sf::IntRect suprafata(c * (lungime + spatiu), r * (inaltime + spatiu), lungime, inaltime);
			atlas[r][c].loadFromFile(numeFisier, suprafata);
		}
	}
	return atlas;
}
