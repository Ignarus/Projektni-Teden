#ifndef IGRALEC_H
#define IGRALEC_H

#include "SDL_Stuff.h"
#include "Polje.h"
#include "Narisi.h"

class Igralec {
private:
	//vector<IPolje*> imam;
	string ime;
	int steviloIgralca;
	int denar;
	int denarnaVrednostVsega;
	SDL_Rect Portret;
	Text ImeTekst;
public:
	Igralec(string ime, int igralec);
	void narisi();
};


#endif

