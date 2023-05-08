#pragma once
#include "ObiectJoc.h"
#define _DESENARE_CUTIE_COLIZIUNE
class CutieColiziune : public ObiectJoc {
private:
public:

	CutieColiziune(Joc* joc);
#ifndef _DESENARE_CUTIE_COLIZIUNE
	void desenare() override {

	}
#endif
};