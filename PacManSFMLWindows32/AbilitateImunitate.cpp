#include "AbilitateImunitate.h"
#include "Monstru.h"
#include "Joc.h"
#include <iostream>
AbilitateImunitate::AbilitateImunitate(Joc* joc) : EventTimp(joc) {
	secundePanaLaTerminare = 5;
	_eventSchimbareAnimatii.secundePanaLaTerminare = 0.15f;
	_eventSchimbareAnimatii.sfarsitEfect = [this]() {
		for (auto& monstru : _joc->monstrii) {
			monstru->incrementareAnimatiiInfricosatIndex();
		}
		_eventSchimbareAnimatii.resetare();
	};
	startEfect = [this]() {
		for (auto& monstru : _joc->monstrii) {
			monstru->activareInfricosare();
		}
	};
	updateEfect = [this]() {
		if (contor() >= 3.5) {
			_eventSchimbareAnimatii.update();
		}
	};
	sfarsitEfect = [this]() {
		for (auto& monstru : _joc->monstrii) {
			monstru->dezactivareInfricosare();
		}
	};
}