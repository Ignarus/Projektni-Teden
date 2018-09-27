#ifndef POLJE_H
#define POLJE_H

#include "SDL_Stuff.h"
#include "Igralec.h"
#include "Igra.h"

//Mankajo cene

enum Akciija
{
	Zacetek,
	DrzavnaBanka,
	DavekNaDohodek,
	Piloznost,
	Zapor,
	Parking,
	PojdiZapor,
	DavekNaPremozenje
};

enum Posebno
{
	//Zahod,
	Elektrika,
	Vlak,
	//Sever,
	//Vzhod,
	Voda,
	//Jug
};

enum Barve
{
	Rjava,
	SvetloModra,
	Vijolcna,
	Oranzna,
	Rdeca,
	Rumena,
	Zelena,
	TemnoModra
};

class Igra;

class IPolje {
protected:
	int ID;
	SDL_Rect KvadratPolje;//polje mesta
public:
	SDL_Rect getKvadrat();//vrne rect vrednosti
	//virtual void action() = 0;
	//virtual void narisi() = 0;
	void KvadratPodatki(int i, Igra TrenutnaIgra);//doloci rect x,y,h,w

};	

class PoljeZAkcijo: IPolje {
private:
	SDL_Texture* Slikca;
	int Vrsta_Akcije;//enum Akcija
public:
	PoljeZAkcijo(int i, Igra TrenutnaIgra);//konstruktor
	void narisi();
};

class ILastniskoPolje: protected IPolje {
protected:
	int cena;
	int IndexIgralec;
public:
	virtual void narisi() = 0;
};

class GradbenoPolje: ILastniskoPolje{
protected:
	SDL_Rect KvadratBarva;//Katero barveno skupino spada izrisat
	int cenaHiske;
	int cenaHotela;
	int BarvenaSkupina;
public:
	GradbenoPolje(int i, Igra TrenutnaIgra);//konstruktor
	//void narisi();
	void BarvniKvadrat(int i,int barva);
	void RenderBarva(int barva);
};

class PosebnoPolje: ILastniskoPolje {
private:
	SDL_Texture * Slikca;
	int VrstaPolja;//enum Posebno
public:
	PosebnoPolje(int i, Igra TrenutnaIgra);//konstruktor
	//void narisi();
};

#endif