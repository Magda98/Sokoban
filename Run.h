#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <TGUI/TGUI.hpp>
#include "Game.h"
#include "MapCreator.h"
#include "Menu.h"
/*!
*	\brief klasa Run
*
*	G³ówny mechanizm gry
*/
class Run
{

private:
	Menu menu;/*!< obiekt typu Menu*/
	Game game;/*!< obiekt typu Game*/
	MapCreator mcreate;/*!< obiekt typu MapCreator*/
	sf::Texture sokoban;/*!< tekstura*/
	sf::RenderWindow &window;/*!< okno gry*/
	tgui::Theme theme{ "BabyBlue.txt" };/*!< motyw do menu*/
	int gameState;/*!< aktualny stan gry*/
	int lvl = 1;/*!< iloœæ etapów*/
	int cPreview;/*!< aktualny rodzaj tekstury w podgl¹dzie */
	bool delLvl = false;/*!< true je¿eli wybrano etap do usuniêcia*/
	bool editLvl = false;/*!< true je¿eli wybrano etap do edycji*/
	void save();
	void creator();
	void start();
	void retry();
	void next();
	void backToMenu();
	void edit();
	void del();
	void disconnectAll();
	void back();
public:
	Run(sf::RenderWindow &window, sf::Texture &sokoban, tgui::Theme &theme);
	//zwraca odpowiedni stan gry
	int getGameState();
	//³¹czy przyciski z odpowiednimi akcjami
	void connectButtons();
	// gameState = 0
	void runMenu(sf::Event &event);
	// gameState = 1
	void runLvlchoose(sf::Event &event);
	// gameState = 3
	void runGame(sf::Event &event);
	// gameState = 4
	void runWin(sf::Event &event);
	// gameState = 5
	void runCreator(sf::Event &event);
	// gameState = 2
	void runEdit(sf::Event &event);
};

