#pragma once
#include "Entity.h"
#include <SFML/Audio.hpp>
#include "Box.h"
#include <SFML/Graphics.hpp>
class Player : public Entity
{

private:
	std::vector<sf::Sprite> wall;
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

