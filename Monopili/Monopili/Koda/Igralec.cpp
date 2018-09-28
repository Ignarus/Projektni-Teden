#include "Igralec.h"


Igralec::Igralec(string ime, int igralec) {
	this->ime = ime;
	lokacija = 0;
	denar = 4000;
	ImeTekst.loadMedia("Roboto-Black.ttf", 35);
	steviloIgralca = igralec;
	switch (igralec){
	case 0:
		Portret.x = SCREEN_WIDTH / 16 * 0.25;
		Portret.y = SCREEN_HEIGHT / 9 * 0.25;
		Portret.w = SCREEN_WIDTH / 16 * 4;
		Portret.h = SCREEN_HEIGHT / 9 * 4;
		break;
	case 1:
		Portret.x = SCREEN_WIDTH / 16 * 11.75;
		Portret.y = SCREEN_HEIGHT / 9 * 0.25;
		Portret.w = SCREEN_WIDTH / 16 * 4;
		Portret.h = SCREEN_HEIGHT / 9 * 4;
		break;
	case 2:
		Portret.x = SCREEN_WIDTH / 16 * 0.25;
		Portret.y = SCREEN_HEIGHT / 9 * 4.75;
		Portret.w = SCREEN_WIDTH / 16 * 4;
		Portret.h = SCREEN_HEIGHT / 9 * 4;
		break;
	case 3:
		Portret.x = SCREEN_WIDTH / 16 * 11.75;
		Portret.y = SCREEN_HEIGHT / 9 * 4.75;
		Portret.w = SCREEN_WIDTH / 16 * 4;
		Portret.h = SCREEN_HEIGHT / 9 * 4;
		break;
	}
}

void Igralec::narisi(bool naVrsti) {
	if (naVrsti) {
		SDL_Rect Poudarek= Portret;
		Poudarek.x -= 3;
		Poudarek.y -= 3;
		Poudarek.w += 6;
		Poudarek.h += 6;
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(gRenderer, &Poudarek);
	}
	Slikca.loadFromFile("Slike/Igralec" + to_string(steviloIgralca + 1)+".png");
	Slikca.resize(60);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xBB, 0xBB, 0xFF);
	SDL_RenderFillRect(gRenderer, &Portret);
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(gRenderer, &Portret);
	SDL_Color Black = { 0,0, 0, 255 };
	ImeTekst.loadFromRenderedText(ime, Black);
	ImeTekst.render(Portret.x + Portret.w/30, Portret.y);
	ImeTekst.loadFromRenderedText("Denar: " + to_string(denar), Black);
	ImeTekst.render(Portret.x + Portret.w / 30, Portret.y + ImeTekst.getHeight());
	if (!bankrot) {
		Slikca.render(Portret.x + Portret.w - Slikca.getWidth() - 10, Portret.y + 10, 0);
	}

}

SDL_Rect Igralec::getKvadrat() {
	return Portret;
}

string Igralec::getName() {
	return ime;
}

void Igralec::narisiFiguro(SDL_Rect Polje){
	if (!bankrot) {
		Slikca.loadFromFile("Slike/Igralec" + to_string(steviloIgralca + 1) + ".png");
		Slikca.resize(Polje.w > Polje.h ? Polje.w / 5 : Polje.h / 5);
		switch (steviloIgralca) {
		case 0:
			Slikca.render(Polje.x, Polje.y, 0);
			break;
		case 1:
			Slikca.render(Polje.x + Polje.w / 2, Polje.y, 0);
			break;
		case 2:
			Slikca.render(Polje.x, Polje.y + Polje.h / 2, 0);
			break;
		case 3:
			Slikca.render(Polje.x + Polje.w / 2, Polje.y + Polje.h / 2, 0);
			break;
		}
	}
}


int Igralec::getLokacijo() {
	return lokacija;
}


void Igralec::premikIgralca(int met) {
	lokacija += met;
	if (lokacija >= 40) {
		lokacija -= 40;
		denar -= 750;
	}
}


void Igralec::prihodek(int denar) {
	this->denar += denar;
}
void Igralec::odhodek(int denar) {
	this->denar -= denar;
}


void Igralec::kupil(IPolje* novaLastnina) {
	imam.push_back(novaLastnina);
}


void Igralec::preveriBankrot() {
	if (denar<0) {
		bankrot = true;
	}
}


bool Igralec::aktiven() {
	return !bankrot;
}