#ifndef IGRA_H
#define IGRA_H

#include "SDL_Stuff.h"
#include "Igralec.h"
#include "Polje.h"

void igra(bool &quit, SDL_Event &e);

class Igra {
private:
	vector<Igralec> Igralci;
	vector<IPolje*> IgralnoPolje;
public:
};

#endif