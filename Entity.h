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
	//ustawia odpowiedni� tekstur� || set right texture
	void setTex(int nm, sf::Texture &sokoban);
	//ustawia odpowiedni� pozyjc� na mapie || set right position on map, x,y <0,12>
	void setPosition(int x, int y);
	//zwraca Sprite'a aby m�c narysowa� obiekt na mapie || get Sprite of object to draw them on map
	sf::Sprite getSprite();
	//przesuwa obiekt na podan� pocyjc� wzgl�dem aktualnej || moving object to specified position from current
	void Move(int width, int height);
	int getYpos();
	int getXpos();
};

