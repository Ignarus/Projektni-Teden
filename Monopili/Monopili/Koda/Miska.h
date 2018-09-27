#ifndef MISKA_H
#define MISKA_H

#include "SDL_Stuff.h"

enum AkcijeMiske {
	Premik,
	LeviGumbDol,
	LeviGumbGor
};

class Miska {
public: 
	Miska();
	void handleEvent(SDL_Event* e);
	SDL_Point getPozicija();
	int getZadnjaAkcija();
private:
	SDL_Point PozicijaMiske;
	int ZadnjaAkcija;
};
#endif