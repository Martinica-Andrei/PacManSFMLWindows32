#pragma once
#include <functional>
#include "ObiectJoc.h"
class EventTimp : public ObiectJoc{
	using functie = void (EventTimp::*)();
private:
	float _contor = 0;
	void _inceput();
	void _update();
	functie _funcCurent = &EventTimp::_inceput;
	// functie care face absolut nimic
	void _functieTerminata() {

	}
public:
	float secundePanaLaTerminare = 0;

	std::function<void()> startEfect = []() {};
	std::function<void()> updateEfect = []() {};
	std::function<void()> sfarsitEfect = []() {};

	EventTimp(Joc* joc);

	void update() override;

	bool esteTerminat() {
		return (_funcCurent == &EventTimp::_functieTerminata);
	}

	void terminare() {
		_funcCurent = &EventTimp::_functieTerminata;
	}

	void resetare();

	float contor() {
		return _contor;
	}
};