#include "Game.h"


Game::Game(sf::Texture & sokoban)
{
	this->sokoban = sokoban;
	pl.setTex(4, sokoban);
	level = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
	};
	steps = 0;
}
void Game::createWalls()
{
	std::vector<sf::Sprite> x = walls.CreateWalls(level);
	pl.setWall(x);
}

void Game::loadTilemap()
{
	map.load(sokoban, sf::Vector2u(map.width, map.height), level, 13, 10);
}


void Game::clearlvl()
{
	steps = 0;
	bx.clear();
	ep.clear();
	pl.setTex(4, sokoban);
}

sf::Sprite Game::getPlayer()
{
	return pl.getSprite();
}

TileMap Game::getTmap()
{
	return map;
}

std::vector<sf::Sprite> Game::getBox()
{

	std::vector<sf::Sprite> sbox;
	for (auto b : bx)
	{
		sbox.push_back(b.getSprite());
	}
	return sbox;
}

std::vector<sf::Sprite> Game::getEndPoint()
{
	std::vector<sf::Sprite> sep;
	for (auto e : ep)
	{
		sep.push_back(e.getSprite());
	}
	return sep;
}

void Game::loadLvl(int x) {
	std::ifstream mapFile("map.txt");
	std::string line;
	for (int i = 1; i <= x; i++)
	{

		if (i == x)
		{
			int num, x, y;
			for (int j = 0; j < 130; j++) {
				mapFile >> num;
				level[j] = num;
			}
			mapFile >> x;
			mapFile >> y;
			pl.setPosition(x, y);
			mapFile >> num;
			for (int k = 0; k < num; k++) {
				Box *element = new Box();
				mapFile >> x;
				mapFile >> y;
				(*element).setTex(20, sokoban);
				(*element).setPosition(x, y);
				bx.push_back(*element);
			}
			for (int k = 0; k < num; k++) {
				EndPoint *element = new EndPoint();
				mapFile >> x;
				mapFile >> y;
				(*element).setTex(24, sokoban);
				(*element).setPosition(x, y);
				ep.push_back(*element);
			}

			break;
		}
		getline(mapFile, line);

	}
	mapFile.close();
	createWalls();
	loadTilemap();
}

void Game::moveUp()
{
	pl.move_up(bx, sokoban, steps);
}

void Game::moveDown()
{
	pl.move_down(bx, sokoban, steps);
}

void Game::moveRight()
{
	pl.move_right(bx, sokoban, steps);
}

void Game::moveLeft()
{
	pl.move_left(bx, sokoban, steps);
}

int Game::getLvlcount()
{
	int ile = 0;
	std::string x;
	std::ifstream mapFile("map.txt");
	while (!mapFile.eof()) {
		std::getline(mapFile, x);
		ile++;
	}
	return ile-1;
}

int Game::getSteps()
{
	return steps;
}

void Game::deleteLvl(int x, int lvl)
{
	std::ifstream mapFile("map.txt");
	std::ofstream temp;
	temp.open("temp.txt");
	std::string line;
	for (int i = 1; i <= lvl; ++i)
	{
		getline(mapFile, line);
		if (i != x)
		{
			temp << line << std::endl;
		}

	}
	mapFile.close();
	temp.close();
	remove("map.txt");
	rename("temp.txt", "map.txt");
}

void Game::checkIfWin(int &gameState) {
	int count = 0;
	for (auto &b : bx) {
		int wew = 0;
		for (auto e : ep)
		{
			if (e.getSprite().getPosition().x == b.getSprite().getPosition().x  && e.getSprite().getPosition().y == b.getSprite().getPosition().y)
			{
				count++;
				b.setTex(21, sokoban);
				wew++;
			}
			else if (wew != 1) {
				b.setTex(20, sokoban);
			}
		}
	}
	if (count == bx.size())
		gameState = 4;
}
