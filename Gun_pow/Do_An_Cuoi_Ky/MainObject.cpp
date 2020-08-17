#include"MainObject.h"

void MainObject::setAmoList(vector<AmoObject*> amoList) { _pAmoList = amoList; }

vector<AmoObject*> MainObject::getAmoList() const { return _pAmoList; }

MainObject::MainObject(){ 
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	_xVal = 0;
	_yVal = 0;
}
MainObject::~MainObject() {

}

void MainObject::handleInput(SDL_Event events) {
	if (events.type == SDL_KEYDOWN) {
		switch (events.key.keysym.sym) {
		case SDLK_UP: {
			_yVal -= HEIGHT_MAIN_OBJECT / 20;
			break;
		} case SDLK_DOWN: {
			_yVal += HEIGHT_MAIN_OBJECT / 20;
			break;
		} case SDLK_LEFT: {
			_xVal -= WIDTH_MAIN_OBJECT / 20;
			break;
		} case SDLK_RIGHT: {
			_xVal += WIDTH_MAIN_OBJECT / 20;
			break;
		}
		}
	} else if (events.type == SDL_KEYUP) {
		switch (events.key.keysym.sym) {
		case SDLK_UP: {
			_yVal += HEIGHT_MAIN_OBJECT / 20;
			break;
		} case SDLK_DOWN: {
			_yVal -= HEIGHT_MAIN_OBJECT / 20;
			break;
		} case SDLK_LEFT: {
			_xVal += WIDTH_MAIN_OBJECT / 20;
			break;
		} case SDLK_RIGHT: {
			_xVal -= WIDTH_MAIN_OBJECT / 20;
			break;
		}
		}
	} else if (events.type == SDL_MOUSEBUTTONDOWN) {
		AmoObject* pAmo = new AmoObject();
		if(events.button.button == SDL_BUTTON_LEFT){
			pAmo->setWidthHeight(WIDTH_LASER, HEIGHT_LASER);
			pAmo->loadImg("laser2.png");
			pAmo->setType(AmoObject::LAZER);
		}
		pAmo->setRect(this->rect_.x + this->rect_.w *0.7, this->rect_.y + this->rect_.h * 0.02);
		pAmo->setIsMove(true);
		pAmo->setX_Val(20);
		_pAmoList.push_back(pAmo);
	}
}

void MainObject::makeAmo(SDL_Surface* g_Something) {
	for (int i = 0; i < _pAmoList.size(); i++) {
		AmoObject* p_amo = _pAmoList.at(i);
		if (p_amo) {
			if (p_amo->getIsMove()) {
				p_amo->show(g_Something);
				p_amo->handleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			}
			else {
				_pAmoList.erase(_pAmoList.begin() + i);
				// free amo
				AmoObject::freeAmo(p_amo);
			}
		}
	}
}

void MainObject::handleMove() {
	rect_.x += _xVal;
	if(rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH) rect_.x -= _xVal;
	rect_.y += _yVal;
	if(rect_.y < 0 || rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT) rect_.y -= _yVal;
}

void MainObject::removeAmo(const int& index) {
	for (int i = 0; i < _pAmoList.size(); i++)
		if (index < _pAmoList.size()) {
			AmoObject* p_amo = _pAmoList.at(index);
			_pAmoList.erase(_pAmoList.begin() + index);
			if (p_amo) {
				delete p_amo;
				p_amo = NULL;
			}
		}
}