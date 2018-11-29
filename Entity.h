#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Entity : public Tile
{
private:
	sf::Sprite sprite;
	int x;
	int y;
public:
	void setTex(int nm, sf::Texture &sokoban);
	void setPosition(int x, int y);
	sf::Sprite getSprite();
	void Move(int width, int height);
	int getYpos();
	int getXpos();
};

