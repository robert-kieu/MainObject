#include"ThreatObject.h"

ThreatObject::ThreatObject() {
	rect_.x = SCREEN_WIDTH;
	rect_.y = SCREEN_HEIGHT*0.5;
	rect_.w = THREAT_WIDTH;
	rect_.h = THREAT_HEIGHT;
	_xVal = 0;
	_yVal = 0;
}
ThreatObject::~ThreatObject(){
	if (_amoList.size() > 0) {
		for (auto i : _amoList) {
			AmoObject* p_amo = i;
			if (p_amo) {
				delete p_amo;
				p_amo = NULL;
			}
		}
		_amoList.clear();
	}
}

void ThreatObject::setX_Val(const int& x) { _xVal = x; }

void ThreatObject::setY_Val(const int& y) { _yVal = y; }

int ThreatObject::getX_Val() const { return _xVal; }

int ThreatObject::getY_Val() const { return _yVal; }

vector<AmoObject*>ThreatObject::getAmoList() const { return _amoList; }

void ThreatObject::setAmoList(const vector<AmoObject*>& list) { _amoList = list; }

void ThreatObject::inItAmo(AmoObject* pAmo) {
	if (pAmo) {
		bool ret = pAmo->loadImg("sphere.png");
		if (ret) {
			pAmo->setIsMove(true);
			pAmo->setWidthHeight(WIDTH_SPHERE, HEIGHT_SPHERE);
			pAmo->setType(AmoObject::SPHERE);
			pAmo->setRect(this->rect_.x, this->rect_.y + this->rect_.h * 0.5);
			// set speed of threat amo
			pAmo->setX_Val(5);
			_amoList.push_back(pAmo);
		}
	}
}

void ThreatObject::makeAmo(SDL_Surface* des, const int& xLimit, const int& yLimit) {
	for (int i = 0; i < _amoList.size(); i++) {
		AmoObject* pAmo = _amoList.at(i);
		if (pAmo) {
			if (pAmo->getIsMove()) {
				pAmo->show(des);
				pAmo->handleMoveRToL();
			} else {
				pAmo->setIsMove(true);
				pAmo->setRect(rect_.x, rect_.y + rect_.h * 0.5);
			}
		}
	}
}

void ThreatObject::handleMove(const int& xBoder, const int& yBoder) {
	rect_.x -= _xVal;
	if (rect_.x < 0) {
		rect_.x = SCREEN_WIDTH;
		int randY = rand() % SCREEN_HEIGHT;
		if (randY > SCREEN_HEIGHT - UNDER_LIMIT) randY = SCREEN_HEIGHT * 0.8;
		rect_.y = randY;
	}
}

//reset pos of threat
void ThreatObject::reset(const int& xBoder) {
	rect_.x = xBoder;
	if (rect_.x < 0) {
		int randY = rand() % SCREEN_HEIGHT;
		if (randY > SCREEN_HEIGHT - UNDER_LIMIT) randY = SCREEN_HEIGHT * 0.8;
		rect_.y = randY;
	}
	for (int i = 0; i < _amoList.size(); i++) {
		AmoObject* p_amo = _amoList.at(i);
		if (p_amo) resetAmo(p_amo);
	}
}

void ThreatObject::resetAmo(AmoObject* p_amo) {
	p_amo->setRect(rect_.x, rect_.y + rect_.h * 0.5);
}

void ThreatObject::handleInput(SDL_Event events) {

}