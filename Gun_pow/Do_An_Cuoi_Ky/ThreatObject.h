#ifndef _THREATOBJECT_H_
#define _THREATOBJECT_H_

#define THREAT_WIDTH 100
#define THREAT_HEIGHT 44
#define UNDER_LIMIT 100

#include"BaseObject.h"
#include"Header.h"
#include"AmoObject.h"

#include<vector>

class ThreatObject : public BaseObject {
public:
	ThreatObject();
	~ThreatObject();

	void handleMove(const int&, const int&);
	void handleInput(SDL_Event);
	
	void setX_Val(const int&);
	void setY_Val(const int&);

	int getX_Val() const;
	int getY_Val() const;

	vector<AmoObject*> getAmoList() const;
	void setAmoList(const vector<AmoObject*>&);

	void inItAmo(AmoObject*);
	void makeAmo(SDL_Surface*, const int&, const int&);

	void reset(const int&);
	void resetAmo(AmoObject*);

private:
	int _xVal, _yVal;
	bool _isAlive, _isCollision, _isStopAmo;
	vector<AmoObject*> _amoList;
};

#endif // !_THREATOBJECT_H_
#pragma once