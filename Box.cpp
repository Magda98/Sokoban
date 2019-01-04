#include "Box.h"


/*!
*	\brief Sprawdza kolizjê miêdzy œcianami mapy, a skrzynk¹
*
*	\return czy mo¿na wykonaæ ruch true/false. 
*
* \param[in] Swall vector obiektów typu Sprite, które zawieraj¹ informacjê o œcianach danje mapy.
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
*	\brief Sprawdza kolizjê miêdzy dwiema skrzynkami
*
*	\return czy mo¿na wykonaæ ruch true/false.
*
*	\param[in] bx vector obiektów typu Box
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