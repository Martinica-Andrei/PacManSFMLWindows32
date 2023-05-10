#include "Monstru.h"	
#include "Joc.h"
#include "Player.h"
#include <algorithm>
Monstru::Monstru(Joc* joc, TIP_MONSTRU tipMonstru) : Entitate(joc), _animatieSus(joc), _animatieDreapta(joc), _animatieJos(joc), _animatieStanga(joc),
_animatieInfricosat1(joc), _animatieInfricosat2(joc) {
	const Texturi& tex = joc->texturi;
	if (tipMonstru == TIP_MONSTRU::albastru) {
		_animatieDreapta.texturi = { &tex.monstruAlbastru[0][0], &tex.monstruAlbastru[0][1] };
		_animatieStanga.texturi = { &tex.monstruAlbastru[0][2], &tex.monstruAlbastru[0][3] };
		_animatieSus.texturi = { &tex.monstruAlbastru[0][4], &tex.monstruAlbastru[0][5] };
		_animatieJos.texturi = { &tex.monstruAlbastru[0][6], &tex.monstruAlbastru[0][7] };
	}
	else if (tipMonstru == TIP_MONSTRU::roz) {
		_animatieDreapta.texturi = { &tex.monstruRoz[0][0], &tex.monstruRoz[0][1] };
		_animatieStanga.texturi = { &tex.monstruRoz[0][2], &tex.monstruRoz[0][3] };
		_animatieSus.texturi = { &tex.monstruRoz[0][4], &tex.monstruRoz[0][5] };
		_animatieJos.texturi = { &tex.monstruRoz[0][6], &tex.monstruRoz[0][7] };
	}
	else if (tipMonstru == TIP_MONSTRU::galben) {
		_animatieDreapta.texturi = { &tex.monstruGalben[0][0], &tex.monstruGalben[0][1] };
		_animatieStanga.texturi = { &tex.monstruGalben[0][2], &tex.monstruGalben[0][3] };
		_animatieSus.texturi = { &tex.monstruGalben[0][4], &tex.monstruGalben[0][5] };
		_animatieJos.texturi = { &tex.monstruGalben[0][6], &tex.monstruGalben[0][7] };
	}
	else if (tipMonstru == TIP_MONSTRU::rosu) {
		_animatieDreapta.texturi = { &tex.monstruRosu[0][0], &tex.monstruRosu[0][1] };
		_animatieStanga.texturi = { &tex.monstruRosu[0][2], &tex.monstruRosu[0][3] };
		_animatieSus.texturi = { &tex.monstruRosu[0][4], &tex.monstruRosu[0][5] };
		_animatieJos.texturi = { &tex.monstruRosu[0][6], &tex.monstruRosu[0][7] };
	}
	_animatieDreapta.secundePeFrame = 0.2;
	_animatieStanga.secundePeFrame = 0.2;
	_animatieSus.secundePeFrame = 0.2;
	_animatieJos.secundePeFrame = 0.2;
	_animatieInfricosat1.secundePeFrame = 0.2;
	_animatieInfricosat2.secundePeFrame = 0.2;
	forma().setScale(32, 32);
	forma().setTexture(_animatieSus.texturaCurenta());
	forma().setOrigin(0.5, 0.5);
	_velocitate = 100.f;

	_animatieInfricosat1.texturi = { &tex.monstruInfricosat[0][0],&tex.monstruInfricosat[0][1] };
	_animatieInfricosat2.texturi = { &tex.monstruInfricosat[0][2],&tex.monstruInfricosat[0][3] };
}

void Monstru::updateAnimatie() {
	if (esteInfricosat == false) {
		if (directieCurenta() == DIR::sus) {
			_animatieSus.update();
			forma().setTexture(_animatieSus.texturaCurenta());
		}
		else if (directieCurenta() == DIR::dreapta) {
			_animatieDreapta.update();
			forma().setTexture(_animatieDreapta.texturaCurenta());
		}
		else if (directieCurenta() == DIR::jos) {
			_animatieJos.update();
			forma().setTexture(_animatieJos.texturaCurenta());
		}
		else if (directieCurenta() == DIR::stanga) {
			_animatieStanga.update();
			forma().setTexture(_animatieStanga.texturaCurenta());
		}
	}
	else {
		_animatieInfricosat1.update();
		forma().setTexture(_animatieInfricosat1.texturaCurenta());
	}
}
void Monstru::update() {
	if (peretiColiziune.count(TIPURI_OBIECTE::usa)) {
		_contorSecundePoarta += _joc->timpDeLaUltimulFrame;
		if (_contorSecundePoarta >= secundePoarta) {
			peretiColiziune.erase(TIPURI_OBIECTE::usa);
		}
	}
	if (drum.size() == 0) {
		int nrRandom = rand() % 100;
		if (nrRandom < 90) {
			drumRandom();
		}
		else {
			drumSprePlayer();
		}
	}
	miscare();
	DIR miscareOprita = oprireMiscareDirectie();
	if (miscareOprita != DIR::null && drum.size()) {
		setareDirectieCurenta(drum.top());
		drum.pop();
	}

	updateAnimatie();

}

void Monstru::drumSprePlayer() {
	auto pozitiePlayer = _joc->player->coordonateMatrice();
	drum = drumCatreCoordonate(pozitiePlayer.y, pozitiePlayer.x);
	if (drum.size()) {
		setareDirectieCurenta(drum.top());
		drum.pop();
	}

}

void Monstru::drumRandom() {
	std::vector<sf::Vector2i> pozitii;
	for (int r = 0; r < _joc->harta->randuri(); r++) {
		for (int c = 0; c < _joc->harta->coloane(); c++) {
			ObiectJoc* obiect = _joc->harta->iaObiect(r, c);
			if (obiect == nullptr || peretiColiziune.count(obiect->tipObiect) == false) {
				pozitii.push_back({ c,r });
			}
		}
	}
	auto& coordRandom = pozitii[rand() % pozitii.size()];
	drum = drumCatreCoordonate(coordRandom.y, coordRandom.x);
	if (drum.size()) {
		setareDirectieCurenta(drum.top());
		drum.pop();
	}
}