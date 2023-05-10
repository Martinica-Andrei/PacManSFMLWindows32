#include "AbilitateImunitate.h"
#include "Monstru.h"
#include "Joc.h"
AbilitateImunitate::AbilitateImunitate(Joc* joc) : EventTimp(joc) {
	secundePanaLaTerminare = 5;
}

void AbilitateImunitate::_startEfect() {
	for (auto& monstru : _joc->monstrii) {
		monstru->esteInfricosat = true;
	}

}
void AbilitateImunitate::_updateEfect() {

}
void AbilitateImunitate::_sfarsitEfect() {
	for (auto& monstru : _joc->monstrii) {
		monstru->esteInfricosat = false;
	}
}