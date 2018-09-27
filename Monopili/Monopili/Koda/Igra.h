#ifndef IGRA_H
#define IGRA_H

#include "SDL_Stuff.h"
#include "Igralec.h"
#include "Polje.h"

void igra(bool &quit, SDL_Event &e);

class Igra {
private:
	vector<Igralec> Igralci;
	vector<IPolje*> Polja;
	SDL_Rect Igralno_polje;
public:
	Igra(int stIgralcev);
	void NarisiVse();
	void NarisiIgralnoPolje();
	void NarisiPortretIgralcev();
	SDL_Rect GetIgralnoPolje();
};

#endif