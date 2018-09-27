#include "Igralec.h"


Igralec::Igralec(string ime, int igralec) {
	this->ime = ime;
	lokacija = 0;
	ImeTekst.loadMedia("Roboto-Black.ttf", 25);
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


void Igralec::narisi() {
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xBB, 0xBB, 0xFF);
	SDL_RenderFillRect(gRenderer, &Portret);
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(gRenderer, &Portret);
	SDL_Color Black = { 0,0, 0, 255 };
	ImeTekst.loadFromRenderedText(ime, Black);
	ImeTekst.render(Portret.x + (Portret.w / 2) - ImeTekst.getWidth() / 2, Portret.y);
}


SDL_Rect Igralec::getKvadrat() {
	return Portret;
}


string Igralec::getName() {
	return ime;
}