#include "EventTimp.h"
#include "Joc.h"
EventTimp::EventTimp(Joc* joc) : ObiectJoc(joc, new sf::RectangleShape({ 1,1 })) {

}

void EventTimp::update() {
	(*this.*_funcCurent)();
}

void EventTimp::_inceput() {
	_funcCurent = &EventTimp::_update;
	startEfect();
}
void EventTimp::_update() {
	_contor += _joc->timpDeLaUltimulFrame;
	if (_contor >= secundePanaLaTerminare) {
		_funcCurent = &EventTimp::_sfarsit;
	}
	else {
		updateEfect();
	}
}
void EventTimp::_sfarsit() {
	_funcCurent = &EventTimp::_functieTerminata;
	sfarsitEfect();
}

void EventTimp::resetare() {
	_funcCurent = &EventTimp::_inceput;
	_contor = 0;
}