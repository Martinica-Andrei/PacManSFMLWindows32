#include "EventTimp.h"
#include "Joc.h"
EventTimp::EventTimp(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })) {

}

void EventTimp::update() {
	(*this.*_funcCurent)();
}

void EventTimp::_inceput() {
	_startEfect();
	_funcCurent = &EventTimp::_update;
}
void EventTimp::_update() {
	_contor += _joc->timpDeLaUltimulFrame;
	if (_contor >= secundePanaLaTerminare) {
		_funcCurent = &EventTimp::_sfarsit;
	}
	else {
		_updateEfect();
	}
}
void EventTimp::_sfarsit() {
	_sfarsitEfect();
	_funcCurent = &EventTimp::_functieTerminata;
}
