#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Walls : public Tile
{
public:
	//tworzy �ciany
	std::vector<sf::Sprite> CreateWalls(std::vector<int> array);
};

