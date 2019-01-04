#pragma once
#include "Entity.h"
#include <SFML/Audio.hpp>
#include "Box.h"
#include <SFML/Graphics.hpp>
/*!
*	\brief klasa Player
*
*	Opisuje poruszanie si� postaci gracza, wykrywanie kolizji gracza ze �cianami i obiekatami typu Box
*/
class Player : public Entity
{

private:
	std::vector<sf::Sprite> wall;/*!< vector obiekt�w typu Sprite */
public:
	//ustawia �ciany etapu
	void setWall(std::vector<sf::Sprite> &w);
	//sprawdza kolizj� mi�dzy graczem a �cianami
	bool checkColission(std::vector<sf::Sprite> Swall);
	//porusza gracza w g�re
	void move_up(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
	//porusza gracza w d�
	void move_down(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
	//porusza gracza w lewo
	void move_left(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
	//porusza gracza w prawo
	void move_right(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
};

