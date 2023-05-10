#pragma once
#include "EventTimp.h"
class AbilitateImunitate : public EventTimp {
private:
protected:
	void _startEfect() override;
	void _updateEfect() override;
	void _sfarsitEfect() override;
public:

	AbilitateImunitate(Joc* joc);
};