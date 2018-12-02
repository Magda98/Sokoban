#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <TGUI/TGUI.hpp>
#include "TileMap.h"
#include "Walls.h"
#include "Player.h"
#include "Entity.h"
#include "Box.h"
#include "EndPoint.h"
#include "Game.h"
#include "MapCreator.h"
#include "Menu.h"
#include "Run.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(832, 640), "Sokoban", sf::Style::Titlebar | sf::Style::Close);
	sf::Texture sokoban;
	sf::Image icon;
	tgui::Theme theme;
	icon.loadFromFile("icon.png");
	sokoban.loadFromFile("sokoban.png");
	theme.load("BabyBlue.txt");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	Run run(window, sokoban, theme);
	run.connectButtons();

	// run the main loop
	while (window.isOpen())
	{
		sf::Event event;
		switch (run.getGameState())
		{
			case 0:
				run.runMenu(event);
				break;

			case 1:
				run.runLvlchoose(event);
				break;

			case 2:
				run.runEdit(event);
				break;

			case 3:
				run.runGame(event);
				break;

			case 4:
				run.runWin(event);
				break;

			case 5:
				run.runCreator(event);
				if (run.getGameState() == 0)
				{
					run.connectButtons();
				}
				break;
		}
	}
	return 0;
}