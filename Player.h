#pragma once
#include "Entity.h"
#include <SFML/Audio.hpp>
#include "Box.h"
#include <SFML/Graphics.hpp>
/*!
*	\brief klasa Player
*
*	Opisuje poruszanie siê postaci gracza, wykrywanie kolizji gracza ze œcianami i obiekatami typu Box
*/
class Player : public Entity
{

private:
	std::vector<sf::Sprite> wall;/*!< vector obiektów typu Sprite */
public:
	//ustawia œciany etapu
	void setWall(std::vector<sf::Sprite> &w);
	//sprawdza kolizjê miêdzy graczem a œcianami
	bool checkColission(std::vector<sf::Sprite> Swall);
	//porusza gracza w góre
	void move_up(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
	//porusza gracza w dó³
	void move_down(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
	//porusza gracza w lewo
	void move_left(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
	//porusza gracza w prawo
	void move_right(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
};

