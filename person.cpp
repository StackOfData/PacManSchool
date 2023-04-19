#include "person.h"

Person::Person(
	SDL_Rect entityRect,
	SDL_Rect entityPicture,
	float speed,
	Direction direction,
	int pointsDeVie
):
	Entity{entityRect, entityPicture},
	speed_{speed},
	direction_{direction},
	pointsDeVie_{pointsDeVie}
{};

Person::~Person() {};

void Person::move(std::vector<SDL_Rect>& walls) {
	if (tryToTurnCmp_ != 60) {
		if (checkDirection(walls, wishDirection_)) {
			tryToTurnCmp_ = 0;
			direction_ = wishDirection_;
		}
		else
			tryToTurnCmp_--;
	}

	switch (direction_) {
		case NONE:
			break;

		case UP:
			this->entityRect_.y -= speed_;
			if (checkWalls(walls, this->entityRect_))
				this->entityRect_.y += speed_;
			break;

		case DOWN:
			this->entityRect_.y += speed_;
			if (checkWalls(walls, this->entityRect_))
				this->entityRect_.y -= speed_;
			break;

		case RIGHT:
			this->entityRect_.x += speed_;
			if (checkWalls(walls, this->entityRect_))
				this->entityRect_.x -= speed_;
			break;

		case LEFT:
			this->entityRect_.x -= speed_;
			if (checkWalls(walls, this->entityRect_))
				this->entityRect_.x += speed_;
			break;

		default:
			//std::cerr << "Person Direction UNKNOW" << SDL_GetError() << std::endl;
			break;
	}
};

/**
 * Wall detection
 * Si le personnage rencontre un mur il renvoie true
 * cela empêchera d'aller dans cette direction
 * */
bool Person::checkWalls(std::vector<SDL_Rect> &walls,SDL_Rect &entity) {
	for (int i=0; i<walls.size();i++) {
		if (SDL_HasIntersection(&entity, &walls[i]))
			return true;
	}
	return false;
};

/**
 * Return true if direction is free
*/
bool Person::checkDirection(std::vector<SDL_Rect> &walls, Direction direction) {
	bool res = true;
	SDL_Rect tmpRect{
		this->entityRect_.x,
		this->entityRect_.y,
		this->entityRect_.w,
		this->entityRect_.h,
	};

	switch (direction) {
		case NONE:
			break;

		case UP:
			tmpRect.y -= speed_+2;
			if (checkWalls(walls, tmpRect))
				res = false;
			break;

		case DOWN:
			tmpRect.y += speed_+2;
			if (checkWalls(walls, tmpRect))
				res = false;
			break;

		case RIGHT:
			tmpRect.x += speed_+2;
			if (checkWalls(walls, tmpRect))
				res = false;
			break;

		case LEFT:
			tmpRect.x -= speed_+2;
			if (checkWalls(walls, tmpRect))
				res = false;
			break;

		default:
			std::cerr << "Person Direction UNKNOW" << SDL_GetError()
				<< std::endl;
			break;
	}

	return res;
};

/**
 * Try to go DOWN, UP, RIGHT, LEFT (in this order)
 * If it can't go in any direction, return false
*/
bool Person::ghostBehavior(std::vector<SDL_Rect> &walls) {
	setWishDirection(Person::DOWN);

	if (checkDirection(walls, wishDirection_) == false)
		setWishDirection(Person::UP);
	else {
		setDirection(Person::DOWN);
		return true;
	}

	if (checkDirection(walls, wishDirection_) == false)
		setWishDirection(Person::RIGHT);
	else {
		setDirection(Person::UP);
		return true;
	}

	if (checkDirection(walls, wishDirection_) == false)
		setWishDirection(Person::LEFT);
	else {
		setDirection(Person::RIGHT);
		return true;
	}

	if (checkDirection(walls, wishDirection_) == false) {
		std::cerr << "Ghost can't move" << std::endl;
		return false;
	}
	else {
		setDirection(Person::LEFT);
		return true;
	}
};