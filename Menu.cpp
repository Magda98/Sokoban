#include "Menu.h"


/*!
*	\brief Konstruktor z parametrami
*
*	konstruktor ustawia odpowiednie pola sk³adowe, wczytuje menu z plików tekstowcyh, ustawia tekstury
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
*	Pobiera widgety do vector'ów z obiektów typu Gui
*/
void Menu::getWidgetlist()
{
	mainWidget = main.getWidgets();
	sideWidget = side.getWidgets();
	winWidget = win.getWidgets();
	editWidget = edit.getWidgets();
}

/*!
*	\brief Ustawia wykrywanie akcji klikniêcia menu g³ównego
*/
void Menu::setMainEventHandler(sf::Event & event)
{
	main.handleEvent(event);
}
/*!
*	\brief Ustawia wykrywanie akcji klikniêcia menu bocznego
*/
void Menu::setSideEventHandler(sf::Event & event)
{
	side.handleEvent(event);
}
/*!
*	\brief Ustawia wykrywanie akcji klikniêcia menu wyboru etapu
*/
void Menu::setLvlEventHandler(sf::Event & event)
{
	chooseLvl.handleEvent(event);
}
/*!
*	\brief Ustawia wykrywanie akcji klikniêcia menu wygranej
*/
void Menu::setWinEventHandler(sf::Event & event)
{
	win.handleEvent(event);
}
/*!
*	\brief Ustawia wykrywanie akcji klikniêcia menu bocznego edycji
*/
void Menu::setEditEventHandler(sf::Event & event)
{
	edit.handleEvent(event);
}
/*!
*	\brief Tworzy odpowiedni¹ liczbê przycisków zale¿nie od iloœci etapów
*
*	Funkcja tworzy przyciski, nastêpnie ustawia je w oknie w odpowiednich miejscach, dodaje ka¿dy z nich do vector'a 
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
*	\brief Zwraca widgety menu g³ównego
*
*	\return vector widgetów menu g³ownego
*/
std::vector<tgui::Widget::Ptr> Menu::getMainWidget()
{
	return mainWidget;
}

/*!
*	\brief Zwraca widgety menu bocznego
*
*	\return vector widgetów menu bocznego
*/
std::vector<tgui::Widget::Ptr> Menu::getSideWidget()
{
	return  sideWidget;
}

/*!
*	\brief Zwraca widgety menu wygranej
*
*	\return vector widgetów menu wygranej
*/
std::vector<tgui::Widget::Ptr> Menu::getWinWidget()
{
	return winWidget;
}

/*!
*	\brief Zwraca przyciski menu wyboru etapu
*
*	\return vector wskaŸników do przycisków menu wyboru etapu
*/
std::vector<tgui::Button::Ptr> & Menu::getLvlButtons()
{
	return lvList;
}
/*!
*	\brief Zwraca wskaŸnik do pola tekstowego w którym znajduje siê liczba kroków
*
*	\return wskaŸnik do pola tekstowego
*/
tgui::TextBox::Ptr Menu::getSteps()
{
	return	side.get<tgui::TextBox>("steps");
}

/*!
*	\brief Zwraca wskaŸnik do etykiety znajduj¹cej siê w menu wygranej, wyœwietlaj¹cej informacje o liczbie kroków
*
*	\return wskaŸnik do etykiety
*/
tgui::Label::Ptr Menu::getStepsTextBox()
{
	return win.get<tgui::Label>("steps");
}

/*!
*	\brief Zwraca widgety menu edycji
*
*	\return vector widgetów menu edycji
*/
std::vector<tgui::Widget::Ptr>  Menu::getEditButtons()
{
	return editWidget;
}

/*!
*	\brief Zwraca TileMap menu g³ównego
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
*	\brief Ustawia liczbê etapów
*
*	\param[in] x liczba etapów
*/
void Menu::setLvl(int x)
{
	lvl = x;
}

/*!
*	\brief Rysuje menu g³ówne w oknie gry
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
*	\brief Zwraca liczbê etapów przechowywan¹ w klasie Menu
*/
int Menu::getLvl()
{
	return lvl;
}

