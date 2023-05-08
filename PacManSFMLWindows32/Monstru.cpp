#include "Monstru.h"	
#include "Joc.h"
Monstru::Monstru(Joc* joc, TIP_MONSTRU tipMonstru) : Entitate(joc), _animatieSus(joc), _animatieDreapta(joc), _animatieJos(joc), _animatieStanga(joc) {
	const Texturi& tex = joc->texturi;
	if (tipMonstru == TIP_MONSTRU::albastru) {
		_animatieDreapta.texturi = {};
		_animatieStanga.texturi = {};
		_animatieSus.texturi = {};
		_animatieJos.texturi = {};
	}
	else if (tipMonstru == TIP_MONSTRU::roz) {
		_animatieDreapta.texturi = {};
		_animatieStanga.texturi = {};
		_animatieSus.texturi = {};
		_animatieJos.texturi = {};
	}
	else if (tipMonstru == TIP_MONSTRU::galben) {
		_animatieDreapta.texturi = {};
		_animatieStanga.texturi = {};
		_animatieSus.texturi = {};
		_animatieJos.texturi = {};
	}
	else if (tipMonstru == TIP_MONSTRU::rosu) {
		_animatieDreapta.texturi = {};
		_animatieStanga.texturi = {};
		_animatieSus.texturi = {};
		_animatieJos.texturi = {};
	}
}