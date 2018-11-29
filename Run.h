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
	int getGameState();
	void connectButtons();
	void runMenu(sf::Event &event);
	void runLvlchoose(sf::Event &event);
	void runGame(sf::Event &event);
	void runWin(sf::Event &event);
	void runCreator(sf::Event &event);
	void runEdit(sf::Event &event);
};

