#include"Header.h"
#ifndef _BASEOBJECT_H_
#define _BASEOBJECT_H_

class BaseObject
{
public:
	BaseObject();
	~BaseObject();

	void show(SDL_Surface*);
	bool loadImg(const char*);

	void setRect(const int&, const int&);
	SDL_Rect getRect() const;
	SDL_Surface* getSurface();
protected:
	SDL_Rect rect_;
	SDL_Surface* p_object_;
};

#endif // !__BASEOBJECT_H_
#pragma once
