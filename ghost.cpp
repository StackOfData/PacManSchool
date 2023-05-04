#include "ghost.h"

Ghost::~Ghost() {};

Ghost::Ghost(
	SDL_Rect entityRect,
	SDL_Rect entityPicture,
	float speed,
	Direction direction,
	Direction wishDirection,
	int healthPoints,
	State status,
	Name name,
	bool outSpawn,
	int timerSpawn
):
	Person{
		entityRect,
		entityPicture,
		speed,
		direction,
		wishDirection,
		healthPoints,
		outSpawn
	},
	name_{name},
	status_{status},
	previousPosition_{entityRect},
	timerSpawn_{timerSpawn}
{}

void Ghost::moveOutOfSpawn(void) {
	if (this->getX() == Coordinate::ghostPinkDefaultPos.x)
		this->setWishDirection(Person::UP);

	else if (this->getX() < Coordinate::ghostPinkDefaultPos.x)
		this->setWishDirection(Person::RIGHT);

	else
		this->setWishDirection(Person::LEFT);
};

Person::Direction Ghost::oppositeDirection(Direction direction) {
	Direction ret = Person::NONE;
	switch (direction) {
		case Person::UP:
			ret = Person::DOWN;
			break;

		case Person::DOWN:
			ret = Person::UP;
			break;

		case Person::LEFT:
			ret = Person::RIGHT;
			break;

		case Person::RIGHT:
			ret = Person::LEFT;
			break;

		default:
			ret = Person::NONE;
			break;
	}

	return ret;
}

void Ghost::moveOutOfSpawn(
	std::vector<SDL_Rect> &walls,
	std::vector<SDL_Rect> &tunnels
) {
	if (this->getStatus() == HUNTER) {
		if (this->getX() == Coordinate::ghostPinkDefaultPos.x)
			this->setWishDirection(Person::UP);

		else if (this->getX() < Coordinate::ghostPinkDefaultPos.x)
			this->setWishDirection(Person::RIGHT);

		else
			this->setWishDirection(Person::LEFT);

		move(walls, tunnels);
	}
}

void Ghost::aleaMove(
	std::vector<SDL_Rect> &walls,
	std::vector<SDL_Rect> &tunnels
) {
	// Ne sort pas du spawn et attend
	if (this->getStatus() == WAIT)
		return;

	std::list<Direction> validDirection;
	intersectionDirection(walls, validDirection);

	//validDirection.remove(previousDirection_);

	// Si à une intersection de 3 chemins minimum
	int size{static_cast<int>(validDirection.size())};
	auto iterList{validDirection.begin()};

	if (size == 3) {
		int nbr{aleaRand(0, size - 1)};
		std::advance(iterList, nbr);
		setWishDirection(*iterList);
	}

	// Si bloqué cherche une autre direction
	if (roundCmpt_ == 2) {
		int nbr{aleaRand(1, 4)};
		switch (nbr) {
			case 1:
				setWishDirection(UP);
				break;

			case 2:
				if (this->getOutSpawn())
					setWishDirection(DOWN);
				break;

			case 3:
				setWishDirection(RIGHT);
				break;

			case 4:
				setWishDirection(LEFT);
				break;

			default:
				break;
		}
		roundCmpt_ = 0;
	}
	else if (SDL_RectEquals(&previousPosition_, &entityRect_) == SDL_TRUE)
		roundCmpt_++;

	previousPosition_ = entityRect_;
	move(walls, tunnels);
	previousDirection_ = this->getDirection();
}

int Ghost::aleaRand(int x, int y) {
	std::random_device rdm;							// Nbr aléatoire du hardware
	std::mt19937 gen(rdm());						// Génère une graine
	std::uniform_int_distribution<> distr(x, y);	// Défini l'intervalle

	return distr(gen);
}

void Ghost::goCoordinate(int x, int y) {
	int selfX{this->entityRect_.x};
	int selfY{this->entityRect_.y};

	if (x > selfX)
		this->setDirection(RIGHT);

	else if (x < selfX)
		this->setDirection(LEFT);
}

void Ghost::eated(void) {
	this->setWishDirection(UP);
	this->resetStatus();
	this->setStatus(WAIT);
	this->setTimerSpawn(Ghost::TIMER_DEAD);

	switch (this->getName()) {
		case BLINKY:
			this->setEntityRect(Coordinate::ghostRedDefaultPos);
			break;

		case PINKY:
			this->setEntityRect(Coordinate::ghostPinkDefaultPos);
			break;

		case INKY:
			this->setEntityRect(Coordinate::ghostBlueDefaultPos);
			break;

		case CLYDE:
			this->setEntityRect(Coordinate::ghostOrangeDefaultPos);
			break;

		default:
			break;
	}
}

void Ghost::resetStatus(void) {
	this->setStatus(HUNTER);

	switch (this->getName()) {
		case BLINKY:
			this->setAnimation(
				Coordinate::ghostRedL,
				Coordinate::ghostRedR,
				Coordinate::ghostRedU,
				Coordinate::ghostRedD
			);
			break;

		case PINKY:
			this->setAnimation(
				Coordinate::ghostPinkL,
				Coordinate::ghostPinkR,
				Coordinate::ghostPinkU,
				Coordinate::ghostPinkD
			);
			break;

		case INKY:
			this->setAnimation(
				Coordinate::ghostBlueL,
				Coordinate::ghostBlueR,
				Coordinate::ghostBlueU,
				Coordinate::ghostBlueD
			);
			break;

		case CLYDE:
			this->setAnimation(
				Coordinate::ghostOrangeL,
				Coordinate::ghostOrangeR,
				Coordinate::ghostOrangeU,
				Coordinate::ghostOrangeD
			);
			break;

		default:
			break;
	}
}

void Ghost::enableGhost(void) {
	if (this->getStatus() == WAIT && this->getTimerSpawn() == 0)
		this->setStatus(HUNTER);
	else
		this->decrementTimerSpawn();
}