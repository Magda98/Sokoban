#include "Box.h"


/*!
*	\brief Sprawdza kolizj� mi�dzy �cianami mapy, a skrzynk�
*
*	\return czy mo�na wykona� ruch true/false. 
*
* \param[in] Swall vector obiekt�w typu Sprite, kt�re zawieraj� informacj� o �cianach danje mapy.
*/
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

/*!
*	\brief Sprawdza kolizj� mi�dzy dwiema skrzynkami
*
*	\return czy mo�na wykona� ruch true/false.
*
*	\param[in] bx vector obiekt�w typu Box
*/
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