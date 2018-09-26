#ifndef POLJE_H
#define POLJE_H

#include "SDL_Stuff.h"
#include "Igralec.h"

class Igralec;

class IPolje {
private:
	int ID;
public:
	int getLocation();
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
	Igralec Lastnik;
	int cena;
public:
};

class GradbenoPolje: ILastniskoPolje {
private:
	//barva
	int cenaHiske;
public:
	void narisi();
};

class PosebnoPolje: ILastniskoPolje {
private:
	//slikca
public:
	void narisi();
};

#endif