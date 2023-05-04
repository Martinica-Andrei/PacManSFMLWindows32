#include "Animatie.h"
#include "Joc.h"
void Animatie::update() {
	_contorSecunde += _joc->timpDeLaUltimulFrame;

	if (_contorSecunde >= secundePeFrame) {
		_contorSecunde = 0;
		_indexCurent++;
		if (_indexCurent == _texturi.size()) {
			_indexCurent = 0;
		}
	}
}

void Animatie::reset() {
	_contorSecunde = 0;
	_indexCurent = 0;
}