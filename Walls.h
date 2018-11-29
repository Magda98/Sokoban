#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

using namespace sf;

class Walls : public Tile
{
public:
	std::vector<sf::Sprite> CreateWalls(std::vector<int> array);
};

