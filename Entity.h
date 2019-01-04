#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Tile.h"

/*!
*	\brief klasa Entity
*	
*	klasa podstawowa po której dziedziczyæ bêd¹ inne klasy, zawiera podstawowe parametry i funkcje sk³adowe
*/
class Entity : public Tile
{
private:
	sf::Sprite sprite; /*!< Sprite danego obiektu */
	int x;/*!< Sk³adowa pozioma pozycji na mapie */
	int y;/*!< Sk³adowa pionowa pozycji na mapie */
public:
	void setTex(int nm, sf::Texture &sokoban);
	void setPosition(int x, int y);
	//zwraca Sprite'a aby móc narysowaæ obiekt na mapie
	sf::Sprite getSprite();
	//przesuwa obiekt na podan¹ pocyjcê wzglêdem aktualnej
	void Move(int width, int height);
	int getYpos();
	int getXpos();
};

