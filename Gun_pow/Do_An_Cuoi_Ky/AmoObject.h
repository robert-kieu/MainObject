#ifndef _AMOOBJECT_H_
#define _AMOOBJECT_H_

#define WIDTH_LASER 38
#define HEIGHT_LASER 7

#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10

#include"BaseObject.h"
#include"Header.h"

class AmoObject : public BaseObject {
private:
	int _xVal, _yVal;
	unsigned int _amoType;
	bool _isMove;
public:
	enum amoType {
		NONE, LAZER, SPHERE
	};

	AmoObject();
	~AmoObject();

	bool getIsMove() const;
	void handleMove(const int&, const int&);
	void handleMoveRToL();

	int getType() const;
	void handleInput(SDL_Event);

	void setIsMove(bool);
	void setType(const int&);

	void setWidthHeight(const int&, const int&);
	static void freeAmo(AmoObject*);

	void setX_Val(const int& val) { _xVal = val; }
	void setY_Val(const int& val) { _yVal = val; }

	int x_Val() { return _xVal; }
	int y_Val() { return _yVal; }
};

#endif // !
#pragma once