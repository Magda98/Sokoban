#include "Menu.h"


/*!
*	\brief Konstruktor z parametrami
*
*	konstruktor ustawia odpowiednie pola sk�adowe, wczytuje menu z plik�w tekstowcyh, ustawia tekstury
*
*	\param[in,out] window okno gry
*	\param[in,out] sokoban tekstura
*/
Menu::Menu(sf::RenderWindow &window, tgui::Theme &theme, sf::Texture &sokoban)
{

	main.setTarget(window);
	side.setTarget(window);
	chooseLvl.setTarget(window);
	win.setTarget(window);
	edit.setTarget(window);

	this->theme = theme;

	main.loadWidgetsFromFile("menu.txt");
	side.loadWidgetsFromFile("side.txt");
	win.loadWidgetsFromFile("win.txt");
	edit.loadWidgetsFromFile("edit.txt");
	this->sokoban = sokoban;
	menuTheme = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 22, 1, 1, 1, 1, 1, 17, 1, 1, 1, 16, 0,
		0, 1, 17, 20, 1, 0, 1, 1, 1, 16, 1, 1, 0,
		0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 22, 1, 0,
		0, 1, 0, 1, 19, 1, 1, 1, 23, 1, 0, 1, 0,
		0, 1, 1, 23, 1, 1, 1, 1, 1, 1, 1, 1, 0,
		0, 18, 0, 1, 1, 1, 1, 1, 0, 22, 1, 15, 0,
		0, 1, 17, 1, 18, 1, 1, 1, 1, 1, 1, 1, 0,
		0, 1, 1, 0, 21, 1, 19, 1, 0, 1, 20, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	buttonTheme = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	mTheme.load(sokoban, sf::Vector2u(width, height), menuTheme, 13, 10);
	bTheme.load(sokoban, sf::Vector2u(width, height), buttonTheme, 13, 10);
	getWidgetlist();

	lvl = 1;
}

/*!
*	\brief Pobiera widgety
*
*	Pobiera widgety do vector'�w z obiekt�w typu Gui
*/
void Menu::getWidgetlist()
{
	mainWidget = main.getWidgets();
	sideWidget = side.getWidgets();
	winWidget = win.getWidgets();
	editWidget = edit.getWidgets();
}

/*!
*	\brief Ustawia wykrywanie akcji klikni�cia menu g��wnego
*/
void Menu::setMainEventHandler(sf::Event & event)
{
	main.handleEvent(event);
}
/*!
*	\brief Ustawia wykrywanie akcji klikni�cia menu bocznego
*/
void Menu::setSideEventHandler(sf::Event & event)
{
	side.handleEvent(event);
}
/*!
*	\brief Ustawia wykrywanie akcji klikni�cia menu wyboru etapu
*/
void Menu::setLvlEventHandler(sf::Event & event)
{
	chooseLvl.handleEvent(event);
}
/*!
*	\brief Ustawia wykrywanie akcji klikni�cia menu wygranej
*/
void Menu::setWinEventHandler(sf::Event & event)
{
	win.handleEvent(event);
}
/*!
*	\brief Ustawia wykrywanie akcji klikni�cia menu bocznego edycji
*/
void Menu::setEditEventHandler(sf::Event & event)
{
	edit.handleEvent(event);
}
/*!
*	\brief Tworzy odpowiedni� liczb� przycisk�w zale�nie od ilo�ci etap�w
*
*	Funkcja tworzy przyciski, nast�pnie ustawia je w oknie w odpowiednich miejscach, dodaje ka�dy z nich do vector'a 
*/
void Menu::createButtons(int lvl)
{
	chooseLvl.removeAllWidgets();
	lvList.clear();
	tgui::Button::Ptr  lvlButton = tgui::Button::create();
	lvlButton->setRenderer(theme.getRenderer("Button"));
	lvlButton->setSize(50, 50);
	lvlButton->setTextSize(20);
	for (int i = 0; i < lvl; ++i) {
		tgui::Button::Ptr button = tgui::Button::copy(lvlButton);
		button->setPosition((i % 11) * width + 71, (i / 11) * height + 71);
		button->setText(std::to_string(i + 1));
		lvList.push_back(button);
	}
	for (const auto& bt : lvList) {
		chooseLvl.add(bt);
	}
}

/*!
*	\brief Zwraca widgety menu g��wnego
*
*	\return vector widget�w menu g�ownego
*/
std::vector<tgui::Widget::Ptr> Menu::getMainWidget()
{
	return mainWidget;
}

/*!
*	\brief Zwraca widgety menu bocznego
*
*	\return vector widget�w menu bocznego
*/
std::vector<tgui::Widget::Ptr> Menu::getSideWidget()
{
	return  sideWidget;
}

/*!
*	\brief Zwraca widgety menu wygranej
*
*	\return vector widget�w menu wygranej
*/
std::vector<tgui::Widget::Ptr> Menu::getWinWidget()
{
	return winWidget;
}

/*!
*	\brief Zwraca przyciski menu wyboru etapu
*
*	\return vector wska�nik�w do przycisk�w menu wyboru etapu
*/
std::vector<tgui::Button::Ptr> & Menu::getLvlButtons()
{
	return lvList;
}
/*!
*	\brief Zwraca wska�nik do pola tekstowego w kt�rym znajduje si� liczba krok�w
*
*	\return wska�nik do pola tekstowego
*/
tgui::TextBox::Ptr Menu::getSteps()
{
	return	side.get<tgui::TextBox>("steps");
}

/*!
*	\brief Zwraca wska�nik do etykiety znajduj�cej si� w menu wygranej, wy�wietlaj�cej informacje o liczbie krok�w
*
*	\return wska�nik do etykiety
*/
tgui::Label::Ptr Menu::getStepsTextBox()
{
	return win.get<tgui::Label>("steps");
}

/*!
*	\brief Zwraca widgety menu edycji
*
*	\return vector widget�w menu edycji
*/
std::vector<tgui::Widget::Ptr>  Menu::getEditButtons()
{
	return editWidget;
}

/*!
*	\brief Zwraca TileMap menu g��wnego
*/
TileMap Menu::getTheme()
{
	return mTheme;
}
/*!
*	\brief Zwraca TileMap menu wyboru etapu/ menu edycji
*/
TileMap Menu::getbTheme()
{
	return bTheme;
}

/*!
*	\brief Ustawia liczb� etap�w
*
*	\param[in] x liczba etap�w
*/
void Menu::setLvl(int x)
{
	lvl = x;
}

/*!
*	\brief Rysuje menu g��wne w oknie gry
*/
void Menu::drawMain()
{
	main.draw();
}

/*!
*	\brief Rysuje menu boczne w oknie gry
*/
void Menu::drawSide()
{
	side.draw();
}

/*!
*	\brief Rysuje menu edycji w oknie gry
*/
void Menu::drawEdit()
{
	edit.draw();
}

/*!
*	\brief Rysuje menu wyboru etapu w oknie gry
*/
void Menu::drawLvl()
{
	chooseLvl.draw();
}

/*!
*	\brief Rysuje menu wygranej w oknie gry
*/
void Menu::drawWin()
{
	win.draw();
}
/*!
*	\brief Zwraca liczb� etap�w przechowywan� w klasie Menu
*/
int Menu::getLvl()
{
	return lvl;
}

