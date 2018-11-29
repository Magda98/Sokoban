#pragma once
#include <fstream>
#include <string.h>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Box.h"
#include "Walls.h"
#include "EndPoint.h"
#include "TileMap.h"
class Game
{
private:
	int steps;
	Player pl;
	std::vector<Box> bx;
	std::vector<EndPoint> ep;
	std::vector<int> level;
	sf::Texture sokoban;
	Walls walls;
	TileMap map;
	void createWalls();
	void loadTilemap();
public:
	Game(sf::Texture &sokoban);
	void deleteLvl(int x, int lvl);
	void checkIfWin(int &gameState);
	void clearlvl();
	sf::Sprite getPlayer();
	TileMap getTmap();
	std::vector<sf::Sprite> getBox();
	std::vector<sf::Sprite> getEndPoint();
	void loadLvl(int x);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	int getLvlcount();
	int getSteps();
};

