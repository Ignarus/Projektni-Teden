#include "Miska.h"


Miska::Miska() {
	PozicijaMiske.x = 0;
	PozicijaMiske.y = 0;
	ZadnjaAkcija = -1;
}
void Miska::handleEvent(SDL_Event* e) {
	int tipAkcije = e->type;

	if(tipAkcije == SDL_MOUSEMOTION || tipAkcije == SDL_MOUSEBUTTONDOWN || tipAkcije == SDL_MOUSEBUTTONUP ) {

		SDL_GetMouseState( &PozicijaMiske.x, &PozicijaMiske.y);
	}
	printf("\r x:%i y:%i ",PozicijaMiske.x, PozicijaMiske.y);

	switch (tipAkcije) {
	case SDL_MOUSEMOTION:
		ZadnjaAkcija = Premik;
		break;
	case SDL_MOUSEBUTTONDOWN:
		ZadnjaAkcija = LeviGumbDol;
		break;
	case SDL_MOUSEBUTTONUP:
		ZadnjaAkcija = LeviGumbGor;
		break;
	}
}

int Miska::getZadnjaAkcija() {

	return ZadnjaAkcija;
}