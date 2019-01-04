#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
/*!
*	\brief	Klasa Walls
*
*	Tworzy vector sprite'ów, z którym bêd¹ wykrywane kolizje
*/
class Walls : public Tile
{
public:
	//tworzy œciany
	std::vector<sf::Sprite> CreateWalls(std::vector<int> array);
};

