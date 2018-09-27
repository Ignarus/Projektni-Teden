#ifndef MISKA_H
#define MISKA_H

#include "SDL_Stuff.h"

enum AkcijeMiske {
	Premik,
	LeviGumbDol,
	LeviGumbGor
};

class LButton {
public: 
	LButton();
	void handleEvent(SDL_Event* e);
	int getZadnjaAkcija();
private:
	SDL_Point PozicijaMiske;
	int ZadnjaAkcija;
};
#endif