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
	void setWall(std::vector<sf::Sprite> &w);
	bool checkColission(std::vector<sf::Sprite> Swall);
	void move_up(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
	void move_down(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
	void move_left(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
	void move_right(std::vector<Box> &bx, sf::Texture &sokoban, int & step);
};

