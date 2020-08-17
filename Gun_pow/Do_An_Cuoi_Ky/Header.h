#ifndef _HEADER_H_
#define _HEADER_H_

#include<Windows.h>
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include<ctime>
#include<iostream>

//=======DECLARE=========

#undef main
using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 675;
const int SCREEN_BPP = 32;
const int NUM_THREATS = 5;

//=======GLOBAL VAR======

SDL_Surface* g_screen = NULL;
SDL_Surface* g_background = NULL;
SDL_Event g_even;
SDL_Surface* g_object;

//=======FUNCTION========

bool inIt();

namespace SDLcommon {
	SDL_Surface* loadImage(string);
	void applySurface(SDL_Surface*, SDL_Surface*, int, int);

	void cleanUp();
	bool checkCollision(const SDL_Rect &, const SDL_Rect &);
}

#pragma once

#endif // !_HEADER_H_
