#include "Narisi.h"

void DrawLine(int x1, int y1, int x2, int y2) {
	SDL_RenderDrawLine(gRenderer, x1, y1, x2, y2);

};


void RectFull(int x1, int y1, int x2, int y2) {
	SDL_Rect fillRect = { x1,y1,x2,y2 };
	SDL_RenderFillRect(gRenderer, &fillRect);
}


void RectEmpty(int x1, int y1, int x2, int y2) {
	SDL_Rect outlineRect = { x1, y1, x2, y2 };
	SDL_RenderDrawRect(gRenderer, &outlineRect);
}