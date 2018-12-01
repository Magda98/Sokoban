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
	//usuwanie etapu || delete the lvl
	void deleteLvl(int x, int lvl);
	//sprawdza czy etap zosta³ przejdziony || check if game is win
	void checkIfWin(int &gameState);
	//czyœci etap, ustawiaj¹c pozycjê odpowiednich obiektów na pocz¹tkowe || clear lvl setting to initial position
	void clearlvl();
	//zwraca Sprite'a gracza, do narysowania go na mapie || get the player Sprite to draw
	sf::Sprite getPlayer();
	//zwraca objekt klasy TileMap, aby móc narysowaæ mapê || get TileMap object to draw map
	TileMap getTmap();
	//zwraca ustalon¹ iloœæ skrzynek || get appropriate quantity of box
	std::vector<sf::Sprite> getBox();
	//zwraca ustalon¹ iloœæ punktów koñcowcyh || get appropriate quantity of Endpoint
	std::vector<sf::Sprite> getEndPoint();
	//wczytuje odpowiedni etap z pliku tekstowego || load appropriate lvl from txt file
	void loadLvl(int x);
	//przesuwanie gracza do góry
	void moveUp();
	//przesuwanie gracza w dó³
	void moveDown();
	//przesuwanie gracza w prawo
	void moveRight();
	//przesuwanie gracza w lewo
	void moveLeft();
	//zwraca liczbê etapów z pliku txt
	int getLvlcount();
	//zwraca liczbê kroków wykonanych przez gracza
	int getSteps();
};

