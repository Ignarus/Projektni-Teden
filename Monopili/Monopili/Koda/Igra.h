#ifndef IGRA_H
#define IGRA_H

#include "SDL_Stuff.h"
#include "Igralec.h"
#include "Polje.h"

void igra(bool &quit, SDL_Event &e);

class Igra {
private:
	std::vector<Igralec> Igralci;
	std::vector<IPolje*> IgralnoPolje;
public:
};

#endif