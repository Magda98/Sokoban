#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
/*!
*	\brief	Klasa Walls
*
*	Tworzy vector sprite'�w, z kt�rym b�d� wykrywane kolizje
*/
class Walls : public Tile
{
public:
	//tworzy �ciany
	std::vector<sf::Sprite> CreateWalls(std::vector<int> array);
};

