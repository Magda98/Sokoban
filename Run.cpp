#include "Run.h"


Run::Run(sf::RenderWindow &rwindow, sf::Texture &sokoban, tgui::Theme &theme) : menu(rwindow, theme, sokoban), game(sokoban), mcreate(sokoban), window(rwindow)
{

	menu.createButtons(game.getLvlcount());
	gameState = 0;
}

void Run::save()
{
	if (!editLvl)
		mcreate.SaveLvl();
	else {
		mcreate.saveEditLvl(game.getLvlcount(), lvl);
		editLvl = false;
		gameState = 2;
	}

	menu.createButtons(game.getLvlcount());
	mcreate.clearMp();
}

void Run::creator()
{
	gameState = 2;
	menu.getSideWidget()[0]->setVisible(false); 
	menu.getSideWidget()[2]->setVisible(true);
}

void Run::start()
{
	if (game.getLvlcount() > 0) {
		gameState = 1;
		menu.getSideWidget()[0]->setVisible(true);
		menu.getSideWidget()[2]->setVisible(false);

		for (auto &bt : menu.getLvlButtons()) {
			bt->disconnectAll();
			bt->connect("clicked", [&]() {
				gameState = 3;
				lvl = int(((bt->getAbsolutePosition().y - 71) / 64) * 11 + (bt->getAbsolutePosition().x - 71) / 64 + 1); });
		}
	}
}

void Run::retry()
{
	game.clearlvl();
	game.loadLvl(lvl);
	gameState = 3;
}

void Run::next()
{
	if (lvl < game.getLvlcount())
	{ 
		game.clearlvl();
		lvl = menu.getLvl() + 1;
		game.loadLvl(lvl);
		gameState = 3; 
	}
}

void Run::backToMenu()
{
	game.clearlvl();
	gameState = 0;
}

void Run::edit()
{
	if (game.getLvlcount() > 0) {
		gameState = 1;
		for (auto &bt : menu.getLvlButtons()) {
			bt->disconnectAll();
			bt->connect("clicked", [&]() {
				lvl = int(((bt->getAbsolutePosition().y - 71) / 64) * 11 + (bt->getAbsolutePosition().x - 71) / 64 + 1);
				mcreate.loadLvl(lvl);
				gameState = 5;
				editLvl = true;
			});
		}
	}
}

void Run::del()
{
	if (game.getLvlcount() > 0) {
		gameState = 1;
		for (auto &bt : menu.getLvlButtons()) {
			bt->disconnectAll();
			bt->connect("clicked", [&]() {lvl = int(((bt->getAbsolutePosition().y - 71) / 64) * 11 + (bt->getAbsolutePosition().x - 71) / 64 + 1);
			game.deleteLvl(lvl, game.getLvlcount());
			menu.createButtons(game.getLvlcount());
			delLvl = true;
			gameState = 2;
			});
		}
	}
}

void Run::disconnectAll()
{
	menu.getMainWidget()[0]->disconnectAll();
	menu.getMainWidget()[1]->disconnectAll();
	menu.getMainWidget()[2]->disconnectAll();



	menu.getSideWidget()[0]->disconnectAll();
	menu.getSideWidget()[1]->disconnectAll();
	menu.getSideWidget()[2]->disconnectAll();


	menu.getWinWidget()[1]->disconnectAll();
	menu.getWinWidget()[2]->disconnectAll();
	menu.getWinWidget()[4]->disconnectAll();

	menu.getEditButtons()[0]->disconnectAll();
	menu.getEditButtons()[1]->disconnectAll();
	menu.getEditButtons()[2]->disconnectAll();
	menu.getEditButtons()[3]->disconnectAll();


}


int Run::getGameState()
{
	return gameState;
}

void Run::connectButtons()
{
	disconnectAll();

	menu.getMainWidget()[0]->connect("pressed", &Run::creator, this);
	menu.getMainWidget()[1]->connect("pressed", [&]() { exit(0); window.close(); });
	menu.getMainWidget()[2]->connect("pressed", &Run::start, this);

	
	menu.getSideWidget()[0]->connect("clicked", &Run::retry, this);
	menu.getSideWidget()[1]->connect("clicked", &Run::backToMenu, this);
	menu.getSideWidget()[2]->connect("clicked", &Run::save, this);

	
	menu.getWinWidget()[1]->connect("clicked", &Run::retry, this);
	menu.getWinWidget()[2]->connect("clicked", &Run::next, this);
	menu.getWinWidget()[4]->connect("clicked", &Run::backToMenu, this);

	menu.getEditButtons()[0]->connect("clicked", [&]() { gameState = 5; });
	menu.getEditButtons()[1]->connect("clicked", &Run::edit, this);
	menu.getEditButtons()[2]->connect("clicked", &Run::del, this);
	menu.getEditButtons()[3]->connect("clicked", [&]() {gameState = 0;});
}

void Run::runMenu(sf::Event & event)
{
	if(window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(0);
		case sf::Event::KeyPressed:

			switch (event.key.code)
			{
			case sf::Keyboard::P:
				gameState = 1;
				break;
			case sf::Keyboard::K:
				gameState = 2;
				break;
			}

		}
		menu.setMainEventHandler(event);
	}
	window.clear(Color(55, 100, 100, 255));
	menu.getTheme().drawMap(window);
	menu.drawMain();
	window.display();
}

void Run::runLvlchoose(sf::Event & event)
{
	if (window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(0);
		}
	}

		if (delLvl == true) {
			this->connectButtons();
			delLvl = false;
		}
		menu.setLvlEventHandler(event);
		window.clear(Color(55, 100, 100, 255));


		if (gameState == 3) {
			game.clearlvl();
			game.loadLvl(lvl);
			menu.setLvl(lvl);
		}

		menu.getbTheme().drawMap(window);
		menu.drawLvl();
		window.display();
}

void Run::runGame(sf::Event & event)
{

	if (window.pollEvent(event))
	{

		switch (event.type)
		{
		case sf::Event::Closed:

			window.close();
			exit(0);

		case sf::Event::KeyPressed:

			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				game.moveUp();
				break;
			case sf::Keyboard::Down:
				game.moveDown();
				break;
			case sf::Keyboard::Left:
				game.moveLeft();
				break;
			case sf::Keyboard::Right:
				game.moveRight();
				break;
			}
		}
	}
		game.checkIfWin(gameState);

		menu.setSideEventHandler(event);
		// draw the map
		window.clear(Color(55, 100, 100, 255));
		game.getTmap().drawMap(window);
		for (auto e : game.getEndPoint()) {
			window.draw(e);
		}
		for (auto b : game.getBox()) {
			window.draw(b);
		}
		window.draw(game.getPlayer());
		menu.getSteps()->setText("\n kroki: " + std::to_string(game.getSteps()) + "\n \n poziom: " + std::to_string(lvl));
		menu.drawGui();
		menu.drawSide();
		window.display();
}

void Run::runWin(sf::Event & event)
{
	if (window.pollEvent(event)) {

		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(0);
		}
	}
		menu.setWinEventHandler(event);
		menu.setLvl(lvl);
		window.clear(Color(55, 100, 100, 255));
		game.getTmap().drawMap(window);
		for (auto e : game.getEndPoint()) {
			window.draw(e);
		}
		for (auto b : game.getBox()) {
			window.draw(b);
		}
		window.draw(game.getPlayer());
		menu.drawWin();
		window.display();
	
}

void Run::runCreator(sf::Event & event)
{
	if (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.clear(Color(55, 100, 100, 255));
			window.close();
			exit(0);
		}

		if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonReleased)
		{
			switch (c % 4) {
			case 0: mcreate.SetMap(sf::Mouse::getPosition(window));
				break;
			case 1:
				mcreate.PlPosition(sf::Mouse::getPosition(window));
				break;
			case 2:
				mcreate.SetMap(sf::Mouse::getPosition(window), 20);
				break;
			case 3:
				mcreate.SetMap(sf::Mouse::getPosition(window), 24);
				break;
			}
		}

		if (event.mouseButton.button == sf::Mouse::Right && event.type == sf::Event::MouseButtonReleased)
		{
			mcreate.SetMap(sf::Mouse::getPosition(window), 1);
		}
		if (event.mouseButton.button == sf::Mouse::Middle && event.type == sf::Event::MouseButtonReleased)
		{
			c++;
			mcreate.setPreview(c);
		}
	}

		window.clear(Color(55, 100, 100, 255));
		menu.setSideEventHandler(event);
		mcreate.getTmap().drawMap(window);
		window.draw(mcreate.getPreview());
		window.draw(mcreate.getPl());
			
		menu.drawSide();
		window.display();
	

}

void Run::runEdit(sf::Event & event)
{
	if (window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(0);
		}
	}
		menu.setEditEventHandler(event);
		window.clear(Color(55, 100, 100, 255));
		menu.getbTheme().drawMap(window);
		menu.drawEdit();
		window.display();
	
}

