#pragma once
#include "EventTimp.h"
class AbilitateImunitate : public EventTimp {
private:
protected:
	EventTimp _eventSchimbareAnimatii {_joc};
public:

	AbilitateImunitate(Joc* joc);
};