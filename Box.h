#pragma once
#include "Entity.h"
/*!
* \brief klasa Box
*
*	klasa obiekt�w typu skrzynki w grze,
*/
class Box : public Entity
{
public:
	bool checkColission(std::vector<sf::Sprite> Swall);
	bool chechBox(std::vector<Box> &bx, Box &xbox);
};

