#include"BaseObject.h"
#include"Header.h"

using namespace SDLcommon;

BaseObject::BaseObject() {
	rect_.x = 0;
	rect_.y = 0;
	p_object_ = NULL;
}

BaseObject::~BaseObject() {
	if (p_object_ != NULL) {
		SDL_FreeSurface(p_object_);
		p_object_ = NULL;
	}
}

void BaseObject::show(SDL_Surface* des) {
	if (p_object_ != NULL) applySurface(p_object_, des, rect_.x, rect_.y);
}

bool BaseObject::loadImg(const char* file) {
	p_object_ = SDLcommon::loadImage(file);
	return (p_object_ == NULL) ? false : true;
}

void BaseObject::setRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; }

SDL_Rect BaseObject::getRect() const { return rect_; }

SDL_Surface* BaseObject::getSurface() { return p_object_; }