#include "Box.h"



bool Box::checkColission(std::vector<sf::Sprite> Swall) {
	bool move = true;
	for (auto wall : Swall) {
		if ((Box::getSprite().getGlobalBounds().intersects(wall.getGlobalBounds())))
		{
			move = false;
		}
	}
	return move;
}

bool Box::chechBox(std::vector<Box> &bx, Box &xbox) {
	bool move = true;
	for (auto &box : bx) {
		if ((Box::getSprite().getGlobalBounds().intersects(box.getSprite().getGlobalBounds())) && &xbox != &box)
		{
			move = false;
		}
	}
	return move;
}