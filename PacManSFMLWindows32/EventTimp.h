#pragma once
#include "ObiectJoc.h"
class EventTimp : ObiectJoc{
	using functie = void (EventTimp::*)();
private:
	float _contor = 0;
	void _inceput();
	void _update();
	void _sfarsit();
	functie _funcCurent = &EventTimp::_inceput;
	// functie care face absolut nimic
	void _functieTerminata() {

	}
protected:
	virtual void _startEfect(){}
	virtual void _updateEfect(){}
	virtual void _sfarsitEfect(){}
public:
	float secundePanaLaTerminare = 0;
	EventTimp(Joc* joc);

	void update() override;

	bool esteTerminat() {
		return (_funcCurent == &EventTimp::_functieTerminata);
	}
};