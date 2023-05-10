#pragma once
#include "EventTimp.h"
class AbilitateImunitate : public EventTimp {
private:
public:

	AbilitateImunitate(Joc* joc);
	void _startEfect() override;
	void _updateEfect() override;
	void _sfarsitEfect() override;
};