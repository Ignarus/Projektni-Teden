#ifndef IGRA_H
#define IGRA_H

#include "SDL_Stuff.h"
#include "Igralec.h"
#include "Polje.h"
#include "Gumb.h"
#include "Miska.h"

void igra(bool &quit, SDL_Event &e);

class Igralec;
class IPolje;

class Igra {
private:
	vector<Igralec> Igralci;
	vector<IPolje*> Polja;
	vector<Gumb> Gumbi;
	SDL_Rect Igralno_polje;
	Miska Curzor;
	int igralec = 0;
public:
	void UpdateCurzoe(SDL_Event* e);
	Igra(int stIgralcev);
	//~Igra();
	void NarisiVse();
	void NarisiIgralnoPolje();
	void NarisiPortretIgralcev();
	void NarisiGumbe();
	void NarisiFigure();
	SDL_Rect GetIgralnoPolje();
	void NarisiVsaPolja();
	void NaslednijIgralec();
	Igralec getTrenutniIgralec();
};

#endif