#ifndef POLJE_H
#define POLJE_H

#include "SDL_Stuff.h"

class IPolje;

class IPolje {
private:
	int ID;
public:
	int getLocation();
	//virtual void action() = 0;
	virtual void narisi() = 0;
};

class PoljeZAkcijo {
private:
	SDL_Texture* Slikca;
public:
	void narisi();
};

class ILastniskoPolje {
private:
	//Igralec* Lastnik;
public:

};

class GradbenoPolje {
private:
	//barva
public:
	void narisi();
};

class PosebnoPolje {
private:
	//slikca
public:
	void narisi();
};

#endif