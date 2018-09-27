#ifndef GUMB_H
#define GUMB_H

#include "SDL_Stuff.h"

class Gumb {
private:
	SDL_Rect Kvadrat;
	string Ukaz;
public:
	Gumb(int zaporedje);
	void narisi();
};

#endif
