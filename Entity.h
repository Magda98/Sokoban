#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Tile.h"

/*!
*	\brief klasa Entity
*	
*	klasa podstawowa po kt�rej dziedziczy� b�d� inne klasy, zawiera podstawowe parametry i funkcje sk�adowe
*/
class Entity : public Tile
{
private:
	sf::Sprite sprite; /*!< Sprite danego obiektu */
	int x;/*!< Sk�adowa pozioma pozycji na mapie */
	int y;/*!< Sk�adowa pionowa pozycji na mapie */
public:
	void setTex(int nm, sf::Texture &sokoban);
	void setPosition(int x, int y);
	//zwraca Sprite'a aby m�c narysowa� obiekt na mapie
	sf::Sprite getSprite();
	//przesuwa obiekt na podan� pocyjc� wzgl�dem aktualnej
	void Move(int width, int height);
	int getYpos();
	int getXpos();
};

