#ifndef GUMB_H
#define GUMB_H

#include "SDL_Stuff.h"
#include "Narisi.h"

class Gumb {
private:
	SDL_Rect Kvadrat;
	string Ukaz;
	Text Napis;
public:
	Gumb(int zaporedje, string besedilo);
	void narisi();
	SDL_Rect getKvadrat();
	void spremeniUkaz(string noviUkaz);
	string getUkaz();
};

#endif
