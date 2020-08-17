#ifndef _MAINOBJECT_H_
#define _MAINOBJECT_H_

#include<vector>

#include"Header.h"
#include"BaseObject.h"
#include"AmoObject.h"

#define WIDTH_MAIN_OBJECT 146
#define HEIGHT_MAIN_OBJECT 70

class MainObject :public BaseObject {
public:
	MainObject();
	~MainObject();

	void handleInput(SDL_Event);
	void handleMove();

	void setAmoList(vector<AmoObject*>);
	vector<AmoObject*> getAmoList() const;

	void makeAmo(SDL_Surface*);
	void removeAmo(const int&);

private:
	int _xVal, _yVal;
	vector<AmoObject*> _pAmoList;
};

#endif // !_MAINOBJECT_H_
#pragma once