#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <TGUI/TGUI.hpp>
#include "Game.h"
#include "MapCreator.h"
#include "Menu.h"
class Run
{

private:
	Menu menu;
	Game game;
	MapCreator mcreate;
	sf::Texture sokoban;
	sf::RenderWindow &window;
	tgui::Theme theme{ "themes/BabyBlue.txt" };
	int gameState;
	int lvl = 1;
	int c;
	bool delLvl = false;
	bool editLvl = false;
	void save();
	void creator();
	void start();
	void retry();
	void next();
	void backToMenu();
	void edit();
	void del();
	void disconnectAll();
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

