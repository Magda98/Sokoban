#pragma once
#include <fstream>
#include <string.h>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Box.h"
#include "Walls.h"
#include "EndPoint.h"
#include "TileMap.h"
/*!
*	\brief klasa Game
*
*	klasa zawieraj�ca informacj� o danej rozgrywce oraz zawieraj�ca metody potrzebne do rozpocz�cia gry
*/
class Game
{
private:
	int steps;/*!< Licznik krok�w*/
	Player pl;/*!< Obiekt typu Player,posta� w grze */
	std::vector<Box> bx;/*!< Vecotr ze skrzynkami*/
	std::vector<EndPoint> ep;/*!< Vector z punktami ko�cowymi*/
	std::vector<int> level;/*!< Vector liczb ca�kowitych, informacje o mapie daneg etapu*/
	sf::Texture sokoban;/*!< Tekstura*/
	Walls walls;/*!< Obiekt typu Walls, informacje o �cianach danej mapy*/
	TileMap map;/*!< Obiekt typu TileMap, informacje o mapie*/
	void createWalls();
	void loadTilemap();
public:
	Game(sf::Texture &sokoban);
	//usuwanie etapu || delete the lvl
	void deleteLvl(int x, int lvl);
	//sprawdza czy etap zosta� przejdziony || check if game is win
	void checkIfWin(int &gameState);
	//czy�ci etap, ustawiaj�c pozycj� odpowiednich obiekt�w na pocz�tkowe || clear lvl setting to initial position
	void clearlvl();
	//zwraca Sprite'a gracza, do narysowania go na mapie || get the player Sprite to draw
	sf::Sprite getPlayer();
	//zwraca objekt klasy TileMap, aby m�c narysowa� map� || get TileMap object to draw map
	TileMap getTmap();
	//zwraca ustalon� ilo�� skrzynek || get appropriate quantity of box
	std::vector<sf::Sprite> getBox();
	//zwraca ustalon� ilo�� punkt�w ko�cowcyh || get appropriate quantity of Endpoint
	std::vector<sf::Sprite> getEndPoint();
	//wczytuje odpowiedni etap z pliku tekstowego || load appropriate lvl from txt file
	void loadLvl(int x);
	//przesuwanie gracza do g�ry
	void moveUp();
	//przesuwanie gracza w d�
	void moveDown();
	//przesuwanie gracza w prawo
	void moveRight();
	//przesuwanie gracza w lewo
	void moveLeft();
	//zwraca liczb� etap�w z pliku txt
	int getLvlcount();
	//zwraca liczb� krok�w wykonanych przez gracza
	int getSteps();
};

