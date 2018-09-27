#include "Gumb.h"


Gumb::Gumb(int zaporedje) {
	Kvadrat.x = SCREEN_WIDTH / 16 * 4.5+(SCREEN_WIDTH / 16*7.25/3* zaporedje);
	Kvadrat.y = SCREEN_HEIGHT / 9 * 7.5;
	Kvadrat.w = SCREEN_WIDTH / 16 * 7.25 / 3 - SCREEN_WIDTH / 16 * 0.25;
	Kvadrat.h = SCREEN_HEIGHT / 9 * 1.25;
}
void Gumb::narisi() {
	SDL_SetRenderDrawColor(gRenderer, 0xCD, 0xE6, 0xD0, 0xFF);
	SDL_RenderFillRect(gRenderer, &Kvadrat);
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(gRenderer, &Kvadrat);
}