#ifndef IGRA_H
#define IGRA_H

#include "SDL_Stuff.h"
#include "Igralec.h"
#include "Polje.h"
#include "Gumb.h"

void igra(bool &quit, SDL_Event &e);

class Igralec;
class IPolje;

class Igra {
private:
	vector<Igralec> Igralci;
	vector<IPolje*> Polja;
	SDL_Rect Igralno_polje;
	vector<Gumb> Gumbi;

public:
	Igra(int stIgralcev);
	void NarisiVse();
	void NarisiIgralnoPolje();
	void NarisiPortretIgralcev();
	void NarisiGumbe();
	SDL_Rect GetIgralnoPolje();
};

#endif