#include "Monstru.h"	
#include "Joc.h"
Monstru::Monstru(Joc* joc, TIP_MONSTRU tipMonstru) : Entitate(joc), _animatieSus(joc), _animatieDreapta(joc), _animatieJos(joc), _animatieStanga(joc) {
	const Texturi& tex = joc->texturi;
	if (tipMonstru == TIP_MONSTRU::albastru) {
		_animatieDreapta.texturi = {&tex.monstruAlbastru[0][0], &tex.monstruAlbastru[0][1] };
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
	forma().setScale(40, 40);
	forma().setTexture(_animatieSus.texturaCurenta());
	_velocitate = 100.f;
}

void Monstru::updateAnimatie() {
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
void Monstru::update() {
	setareDirectieCurenta(DIR::stanga);
	updateAnimatie();

}

void Monstru::ai() {

}