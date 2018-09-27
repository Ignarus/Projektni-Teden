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
class Igralec;

class IPolje {
protected:
	int ID;
	SDL_Rect KvadratPolje;//polje mesta
public:
	SDL_Rect getKvadrat();//vrne rect vrednosti
	//virtual void action() = 0;
	virtual void narisi() = 0;
	void KvadratPodatki(int i, Igra TrenutnaIgra);//doloci rect x,y,h,w

};	

class PoljeZAkcijo: public IPolje {
private:
	SDL_Texture* Slikca;
	int Vrsta_Akcije;//enum Akcija
public:
	PoljeZAkcijo(int i, Igra TrenutnaIgra);//konstruktor
	void narisi();
};

class ILastniskoPolje: public IPolje {
protected:
	//Igralec * Lastnik;
	int cena;
	int IndexIgralec;
	int najem;
	int SteviloParov;
	int VelikostParov;
public:
	virtual void narisi() = 0;
};

class GradbenoPolje: public ILastniskoPolje{
protected:
	SDL_Rect KvadratBarva;//Katero barveno skupino spada izrisat
	int cenaHiske;
	int cenaHotela;
	int BarvenaSkupina;
	int SteviloHis;
	bool Hotel;
public:
	GradbenoPolje(int i, Igra TrenutnaIgra);//konstruktor
	void BarvniKvadrat(int i,int barva);
	void RenderBarva(int barva);
	void narisi();
};

class PosebnoPolje: public ILastniskoPolje {
private:
	SDL_Texture * Slikca;
	int VrstaPolja;//enum Posebno
public:
	PosebnoPolje(int i, Igra TrenutnaIgra);//konstruktor
	void narisi();
};

#endif