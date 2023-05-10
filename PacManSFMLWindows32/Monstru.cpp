#include "Monstru.h"	
#include "Joc.h"
#include "Player.h"
#include <algorithm>
Monstru::Monstru(Joc* joc, TIP_MONSTRU tipMonstru) : Entitate(joc), _animatieSus(joc), _animatieDreapta(joc), _animatieJos(joc), _animatieStanga(joc) {
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
	forma().setScale(32, 32);
	forma().setTexture(_animatieSus.texturaCurenta());
	forma().setOrigin(0.5, 0.5);
	_velocitate = _velocitateNormala;

	_animatiiInfricosat.push_back({ joc,  { &tex.monstruInfricosat[0][0],&tex.monstruInfricosat[0][1] } });
	_animatiiInfricosat.push_back({ joc,  { &tex.monstruInfricosat[0][2],&tex.monstruInfricosat[0][3] } });
	for (auto& anim : _animatiiInfricosat) {
		anim.secundePeFrame = 0.2;
	}
}
void Monstru::updateAnimatieNormal() {
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
void Monstru::updateAnimatieInfricosat() {
	for (auto& anim : _animatiiInfricosat) {
		anim.update();
	}
	forma().setTexture(_animatiiInfricosat[_animatiiInfricosatIndex].texturaCurenta());
}
void Monstru::updateAnimatieOchi() {
	if (directieCurenta() == DIR::sus) {
		forma().setTexture(&_joc->texturi.monstruOchi[0][2]);
	}
	else if (directieCurenta() == DIR::dreapta) {
		forma().setTexture(&_joc->texturi.monstruOchi[0][0]);
	}
	else if (directieCurenta() == DIR::jos) {
		forma().setTexture(&_joc->texturi.monstruOchi[0][3]);
	}
	else if (directieCurenta() == DIR::stanga) {
		forma().setTexture(&_joc->texturi.monstruOchi[0][1]);
	}
}
void Monstru::updateAnimatie() {
	if (_esteRespawn) {
		updateAnimatieOchi();
	}
	else if (_esteInfricosat == false) {
		updateAnimatieNormal();
	}
	else {
		updateAnimatieInfricosat();
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
		if (_esteRespawn) {
			_esteRespawn = false;
			_velocitate = _velocitateNormala;
		}
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


void Monstru::coliziune(Player& player) {
	if (_esteRespawn) return;
	auto rect = forma().getGlobalBounds();
	if (rect.intersects(player.forma().getGlobalBounds())) {
		if (_esteInfricosat == false) {
			_joc->eGameOver = true;
		}
		else {
			respawn();
		}
	}
}

void Monstru::activareInfricosare() {
	if (_esteRespawn == false) {
		_esteInfricosat = true;
		_velocitate = _velocitateInfricosat;
	}
}
void Monstru::dezactivareInfricosare() {
	if (_esteInfricosat) {
		_esteInfricosat = false;
		_animatiiInfricosatIndex = 0;
		_velocitate = _velocitateNormala;
	}
}

void Monstru::respawn() {
	_esteRespawn = true;
	_esteInfricosat = false;
	_velocitate = _velocitateRespawn;
	drum = drumCatreCoordonate(15, 11);
	if (drum.size()) {
		setareDirectieCurenta(drum.top());
		drum.pop();
	}
}

void Monstru::incrementareAnimatiiInfricosatIndex() {
	_animatiiInfricosatIndex++;
	if (_animatiiInfricosatIndex >= _animatiiInfricosat.size()) {
		_animatiiInfricosatIndex = 0;
	}

}

void Monstru::setareAnimatiiInfricosatIndex(int val) {
	_animatiiInfricosatIndex = val;
	if (_animatiiInfricosatIndex >= _animatiiInfricosat.size()) {
		_animatiiInfricosatIndex = 0;
	}
}