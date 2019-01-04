#include "Run.h"
/*!
*	\brief	 konstruktor z parametrami i list¹ inicializacyjn¹
*
*	\param[in,out] rwindow okno gry
*	\param[in,out] sokoban tekstura
*	\param[in,out] theme motyw menu
*/
Run::Run(sf::RenderWindow &rwindow, sf::Texture &sokoban, tgui::Theme &theme) : menu(rwindow, theme, sokoban), game(sokoban), mcreate(sokoban), window(rwindow)
{

	menu.createButtons(game.getLvlcount());
	gameState = 0;
}
/*!
*	\brief zapisuje etap
*
*	W zale¿noœci od tego czy zapisujemu etap edytowany czy nowy
*/
void Run::save()
{
	if (!editLvl)
	{
		mcreate.SaveLvl();
		gameState = 2;
	}
	else {
		mcreate.saveEditLvl(game.getLvlcount(), lvl);
		editLvl = false;
		gameState = 2;
	}

	menu.createButtons(game.getLvlcount());
	mcreate.clearMp();
}

/*!
*	\brief ustawia widocznoœæ przycisków dla kreatora map
*/
void Run::creator()
{
	gameState = 2;
	menu.getSideWidget()[3]->setVisible(false);
	menu.getSideWidget()[0]->setVisible(false); 
	menu.getSideWidget()[2]->setVisible(true);

}

/*!
*	\brief	³¹czy przyciski w meny wyboru etapu z odpowiedni¹ funkcj¹
*/
void Run::start()
{
	menu.getEditButtons()[0]->setVisible(false);
	menu.getEditButtons()[1]->setVisible(false);
	menu.getEditButtons()[2]->setVisible(false);
	menu.getEditButtons()[3]->setVisible(false);
	menu.getEditButtons()[4]->setVisible(false);
	menu.getSideWidget()[3]->setVisible(true);
	if (game.getLvlcount() > 0) {
		gameState = 1;
		menu.getSideWidget()[0]->setVisible(true);
		menu.getSideWidget()[2]->setVisible(false);

		for (auto &bt : menu.getLvlButtons()) {
			bt->disconnectAll();
			bt->connect("clicked", [&]() {
				gameState = 3;
				lvl = int(((bt->getAbsolutePosition().y - 71) / menu.width) * 11 + (bt->getAbsolutePosition().x - 71) / menu.height + 1); });
		}
	}
}

/*!
*	\brief resetuje etap
*/
void Run::retry()
{
	game.clearlvl();
	game.loadLvl(lvl);
	gameState = 3;
}

/*!
*	\brief przechodzi do nastêpnego etapu
*/
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
/*!
*	\brief powrót do menu, czyszczenie aktualnego etapu
*/
void Run::backToMenu()
{
	game.clearlvl();
	gameState = 0;
}

/*!
*	\brief wyœwietla przyciski listy etapów w menu edycji, ³¹czy je z odpowiedni¹ funkcj¹
*/
void Run::edit()
{
	menu.getEditButtons()[0]->setVisible(false);
	menu.getEditButtons()[1]->setVisible(false);
	menu.getEditButtons()[2]->setVisible(false);
	menu.getEditButtons()[3]->setVisible(false);
	menu.getEditButtons()[4]->setVisible(true);
	if (game.getLvlcount() > 0) {
		gameState = 1;
		for (auto &bt : menu.getLvlButtons()) {
			bt->disconnectAll();
			bt->connect("clicked", [&]() {
				lvl = int(((bt->getAbsolutePosition().y - 71) / menu.width) * 11 + (bt->getAbsolutePosition().x - 71) / menu.height + 1);
				mcreate.loadLvl(lvl);
				gameState = 5;
				editLvl = true;
			});
		}
	}
}

/*!
*	\brief	 wyœwietla przyciski listy etapów w menu usuwania, ³¹czy je z odpowiedni¹ funkcj¹
*/
void Run::del()
{
	menu.getEditButtons()[0]->setVisible(false);
	menu.getEditButtons()[1]->setVisible(false);
	menu.getEditButtons()[2]->setVisible(false);
	menu.getEditButtons()[3]->setVisible(false);
	menu.getEditButtons()[4]->setVisible(true);
	if (game.getLvlcount() > 0) {
		gameState = 1;
		for (auto &bt : menu.getLvlButtons()) 
		{
			bt->disconnectAll();
			bt->connect("clicked", [&]() {lvl = int(((bt->getAbsolutePosition().y - 71) / menu.width) * 11 + (bt->getAbsolutePosition().x - 71) / menu.height + 1);
				game.deleteLvl(lvl, game.getLvlcount());
				menu.createButtons(game.getLvlcount());
				delLvl = true;
				gameState = 2;
			});
		}
	}
}

/*!
*	\brief	 roz³¹cza wszystkie przyciski z funkcjami
*/
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
	menu.getEditButtons()[4]->disconnectAll();


}

/*!
*	\brief	 powrót do poprzedniego menu, ustawienie widocznoœci odpowiednich przyscików
*/
void Run::back()
{
	menu.getEditButtons()[0]->setVisible(true);
	menu.getEditButtons()[1]->setVisible(true);
	menu.getEditButtons()[2]->setVisible(true);
	menu.getEditButtons()[3]->setVisible(true);
	menu.getEditButtons()[4]->setVisible(false);
	gameState = 2;
}

/*!
*	\brief	 pobiera aktualny stan gry
*/
int Run::getGameState()
{
	return gameState;
}

/*!
*	\brief	 ³¹czy wszystkie przyciski z odpowiednimi funkcjami
*/
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
	menu.getEditButtons()[4]->connect("clicked", &Run::back, this);
}

/*!
*	\brief	 odpowiada za menu g³ówne
*
*	Rysuje na oknie menu g³ówne oraz t³o menu g³ównego
*
*	\param[in,out] event zdarzenie wykryte w oknie gry
*/
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
	window.clear(sf::Color(55, 100, 100, 255));
	menu.getTheme().drawMap(window);
	menu.drawMain();
	window.display();
}

/*!
*	\brief	 Odpowiada za menu wyboru etapu
*
*	Rysuje menu wyboru etapu oraz t³o
*
*	\param[in,out] event zdarzenie wykryte w oknie gry
*/
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
	menu.setEditEventHandler(event);
	window.clear(sf::Color(55, 100, 100, 255));

	if (gameState == 3) {
		game.clearlvl();
		game.loadLvl(lvl);
		menu.setLvl(lvl);
	}

	menu.getbTheme().drawMap(window);
	menu.drawLvl();
	menu.drawEdit();
	window.display();
}

/*!
*	\brief	 odpowiada za planszê
*
*	Rysuje na oknie planszê, wykrywa naciœniecie klawiszy sterowania, rysuje menu boczne, rysuje skrzynki, punkty koñcowe oraz postaæ gracza na mapie
*
*	\param[in,out] event zdarzenie wykryte w oknie gry
*/
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
	window.clear(sf::Color(55, 100, 100, 255));
	game.getTmap().drawMap(window);
	for (auto e : game.getEndPoint()) {
		window.draw(e);
	}
	for (auto b : game.getBox()) {
		window.draw(b);
	}
	window.draw(game.getPlayer());
	menu.getSteps()->setText("\n kroki: " + std::to_string(game.getSteps()) + "\n \n poziom: " + std::to_string(lvl));
	menu.drawSide();
	window.display();
}

/*!
*	\brief	 odpowiada za menu wygranej
*
*	Rysuje na oknie menu wygranej, je¿eli etap zosta³ przejdziony
*
*	\param[in,out] event zdarzenie wykryte w oknie gry
*/
void Run::runWin(sf::Event & event)
{
	if (lvl == game.getLvlcount())
	{
		menu.getWinWidget()[2]->setVisible(false);
		menu.getStepsTextBox()->setText("kroki: " + std::to_string(game.getSteps()) + "\nTo jest ostatni etap!");
	}
	else
	{
		menu.getWinWidget()[2]->setVisible(true);
		menu.getStepsTextBox()->setText("kroki: " + std::to_string(game.getSteps()));
	}
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
	window.clear(sf::Color(55, 100, 100, 255));
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

/*!
*	\brief	 odpowiada za kreator map
*
*	Rysuje na oknie mapê kreatora map, wykrywa kliknieæie mysz¹ ustawiaj¹c dan¹ teksturê w klikniêtym miejscu mapy, usuwanie dodanej tekstury za pomoc¹ prawego przycisku myszy, zmienia rodzaj tekstury inkrementujac licznik b¹dŸ dekrementuj¹c - scroll up lub scroll down, 
*
*	\param[in,out] event zdarzenie wykryte w oknie gry
*/
void Run::runCreator(sf::Event & event)
{
	if (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.clear(sf::Color(55, 100, 100, 255));
			window.close();
			exit(0);
		}

		if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonReleased)
		{
			switch (abs(cPreview) % 4) {
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
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::P )
		{
			cPreview++;
			mcreate.setPreview(cPreview);
		}
		if (event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta > 0)
		{
			cPreview++;
			mcreate.setPreview(cPreview);
		}
		if (event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta < 0)
		{
			cPreview--;
			mcreate.setPreview(cPreview);
		}
	}
	window.clear(sf::Color(55, 100, 100, 255));
	menu.setSideEventHandler(event);
	mcreate.getTmap().drawMap(window);
	window.draw(mcreate.getPreview());
	window.draw(mcreate.getPl());
	menu.drawSide();
	window.display();
}

/*!
*	\brief	 odpowiada za menu edycji
*
*	Rysuje na oknie menu edycji
*
*	\param[in,out] event zdarzenie wykryte w oknie gry
*/
void Run::runEdit(sf::Event & event)
{
	menu.getEditButtons()[0]->setVisible(true);
	menu.getEditButtons()[1]->setVisible(true);
	menu.getEditButtons()[2]->setVisible(true);
	menu.getEditButtons()[3]->setVisible(true);
	menu.getEditButtons()[4]->setVisible(false);
	if (window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(0);
		}
	}
	menu.setEditEventHandler(event);
	window.clear(sf::Color(55, 100, 100, 255));
	menu.getbTheme().drawMap(window);
	menu.drawEdit();
	window.display();
	
}

