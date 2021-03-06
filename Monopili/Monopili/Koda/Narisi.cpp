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


Texture::Texture()
{
	//Initialize 
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}
Texture::~Texture()
{
	//Deallocate 
	free();
}
void Texture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}
bool Texture::loadFromFile(std::string path)
{
	//Get rid of preexisting texture 
	free();
	//The final texture 
	SDL_Texture* newTexture = NULL;
	//Load image at specified path 
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image 
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));
		//Create texture from surface pixels 
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		//Get rid of old loaded surface 
		SDL_FreeSurface(loadedSurface);
	}
	//Return success 
	mTexture = newTexture;
	return mTexture != NULL;
}
void Texture::sizechange(float changesize) {
	mWidth *= changesize;
	mHeight *= changesize;
}
void Texture::resize(float size) {
	mWidth = size;
	mHeight = size;
}
int Texture::getWidth()
{
	return mWidth;
}
int Texture::getHeight()
{
	return mHeight;
}
void Texture::render(int x, int y, double angle)
{
	SDL_Rect* clip = NULL;
	SDL_Point* center = NULL;
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, SDL_FLIP_NONE);
}