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
	_update();
}
void EventTimp::_update() {
	_contor += _joc->timpDeLaUltimulFrame;
	if (_contor >= secundePanaLaTerminare) {
		_funcCurent = &EventTimp::_functieTerminata;
		sfarsitEfect();
	}
	else {
		updateEfect();
	}
}

void EventTimp::resetare() {
	_funcCurent = &EventTimp::_inceput;
	_contor = 0;
}