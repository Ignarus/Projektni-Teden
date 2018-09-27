#ifndef NARISI_H
#define NARISI_H

#include "SDL_Stuff.h"

void DrawLine(int x1, int y1, int x2, int y2);

void RectFull(int x1, int y1, int x2, int y2);

void RectEmpty(int x1, int y1, int x2, int y2);

class Text {
public:
	Text();
	~Text();
	bool loadMedia(std::string path, int size);
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
	void free();
	void render(int x, int y);
	int getWidth();
	int getHeight();
private:
	SDL_Texture * mTexture;
	int mWidth;
	int mHeight;
};

class Texture {
public:
	Texture();
	~Texture();
	bool loadFromFile(std::string path);
	void free();
	void sizechange(float changesize);
	void render(int x, int y, double angle = 0.0);
	void resize(float size);
	int getWidth();
	int getHeight();
protected:
	SDL_Texture * mTexture;
	int mWidth;
	int mHeight;
};

#endif

