#include "Texturi.h"

Texturi::Texturi() {
	pacman_1.loadFromFile("data\\pacman_1.png");
	pacman_2.loadFromFile("data\\pacman_2.png");
	cutieColiziune.loadFromFile("data\\cutie_coliziune.png");
	background.loadFromFile("data\\background.png");
	harta = incarcareAtlas("data\\harta.png", 3, 16, 8, 8, 1);
	hartaClipire = incarcareAtlas("data\\harta_clipit.png", 3, 16, 8, 8, 1);

	monstruRosu = incarcareAtlas("data\\monstrii\\rosu.png", 1, 8, 14, 14, 2);
	monstruRoz = incarcareAtlas("data\\monstrii\\roz.png", 1, 8, 14, 14, 2);
	monstruAlbastru = incarcareAtlas("data\\monstrii\\albastru.png", 1, 8, 14, 14, 2);
	monstruGalben = incarcareAtlas("data\\monstrii\\galben.png", 1, 8, 14, 14, 2);

	monstruInfricosat = incarcareAtlas("data\\monstrii\\infricosat.png", 1, 4, 14, 14, 2);
	monstruOchi = incarcareAtlas("data\\monstrii\\ochi.png", 1, 4, 14, 14, 2);
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
