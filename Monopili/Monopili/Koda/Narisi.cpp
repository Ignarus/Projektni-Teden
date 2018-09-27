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



Text::Text() {
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}
Text::~Text() {
	free();
}
bool Text::loadMedia(std::string path, int size) {
	bool success = true;
	gFont = TTF_OpenFont(path.c_str(), size);
	if (gFont == NULL) {
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	return success;
}
bool Text::loadFromRenderedText(std::string textureText, SDL_Color textColor) {
	//Get rid of preexisting texture 
	free();
	//Render text surface 

	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL) {
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else {
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL) {
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else {
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}
		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	} //Return success 
	return mTexture != NULL;
}
void Text::free() {
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}
void Text::render(int x, int y) {
	SDL_Rect* clip = NULL;
	SDL_Point* center = NULL;
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(gRenderer, mTexture, NULL, &renderQuad, 0, NULL, SDL_FLIP_NONE);
}
int Text::getWidth() {
	return mWidth;
}
int Text::getHeight() {
	return mHeight;
}
