#pragma once
#include "Entity.h"
class Box : public Entity
{
public:
	bool checkColission(std::vector<sf::Sprite> Swall);
	bool chechBox(std::vector<Box> &bx, Box &xbox);
};

