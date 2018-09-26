#ifndef POLJE_H
#define POLJE_H

#include "SDL_Stuff.h"
#include "Igralec.h"


class IPolje {
private:
	int ID;
	SDL_Rect KvadratPolje;//polje mesta
public:
	SDL_Rect getKvadrat();//vrne rect vrednosti
	void SetKvadraat(SDL_Rect );
	//virtual void action() = 0;
	virtual void narisi() = 0;
};

class PoljeZAkcijo: IPolje {
private:
	SDL_Texture* Slikca;
public:
	void narisi();
};

class ILastniskoPolje: IPolje {
private:
	int cena;
public:
	virtual void narisi() = 0;
};

class GradbenoPolje: ILastniskoPolje {
private:
	//barva
	SDL_Rect KvadratBarva;//Katero barveno skupino spada
	int cenaHiske;
public:
	void narisi();
};

class PosebnoPolje: ILastniskoPolje {
private:
	SDL_Texture * Slikca;
public:
	void narisi();
};

#endif