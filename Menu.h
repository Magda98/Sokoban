#pragma once
#include <TGUI/TGUI.hpp>
#include <fstream>
#include <iostream>
#include "TileMap.h"
/*!
*	\brief	klasa Manu
*
*	Klasa odpowiedzialna za menu g�owne, menu boczne, menu edytora, menu wygranej
*/
class Menu : public Tile
{
private:
	sf::Texture sokoban;/*!< tekstura*/
	tgui::Gui main;/*!< interfejs menu g��wnego*/
	tgui::Gui side;/*!< interfejs menu bocznego*/
	tgui::Gui chooseLvl;/*!< interfejs menu wyboru etapu*/
	tgui::Gui win;/*!< interfejs menu wygranej*/
	tgui::Gui edit;/*!< interfejs menu edycji*/
	tgui::Theme theme;/*!< motyw menu*/
	std::vector<tgui::Widget::Ptr> mainWidget;/*!< widgety menu g��wnego*/
	std::vector<tgui::Widget::Ptr> winWidget;/*!< widgety menu wygranej*/
	std::vector<tgui::Widget::Ptr> sideWidget;/*!< widgety bocznego menu*/
	std::vector<tgui::Widget::Ptr> editWidget;/*!< widgety menu edycji*/
	std::vector<int> menuTheme;/*!< t�o menu g�ownego*/
	std::vector<int> buttonTheme;/*!< t�o menu wyboru etapu/menu edycji*/
	TileMap bTheme;/*!< TileMap t�a menu wyboru etapu/menu edycji*/
	TileMap mTheme;/*!< TileMap menu g��wnego*/
	int lvl;/*!< przechowuje informacje o liczbie etap�w*/
	std::vector<tgui::Button::Ptr> lvList;/*!< vector przechowujacy wska�niki do przycisk�w poziom�w*/
	void getWidgetlist();
public:
	Menu(sf::RenderWindow &window, tgui::Theme &theme, sf::Texture &sokoban);
	//ustawia Event dla menu g��wnego
	void setMainEventHandler(sf::Event &event);
	//ustawia Event dla menu bocznego
	void setSideEventHandler(sf::Event & event);
	//ustawia Event dla menu wyboru etap�w
	void setLvlEventHandler(sf::Event & event);
	//ustawia Event dla menu po wygranej
	void setWinEventHandler(sf::Event & event);
	//ustawia Event dla menu w edycji map
	void setEditEventHandler(sf::Event & event);
	//tworzy odpowieni� liczb� przycisk�w w zale�no�ci od ilo�ci etap�w wczytanych z pliku
	void createButtons(int lvl);
	//ustawia zmienn� z aktualnym etap
	void setLvl(int x);
	//zwraca Widgety menu g��wnego
	std::vector<tgui::Widget::Ptr> getMainWidget();
	//zwraca Widgety menu bocznego
	std::vector<tgui::Widget::Ptr> getSideWidget();
	//zwraca Widgety menu wygranej
	std::vector<tgui::Widget::Ptr> getWinWidget();
	//zwraca Widgety menu edycji
	std::vector<tgui::Widget::Ptr>  getEditButtons();
	//zwraca Widgety menu wyboru etap�w
	std::vector<tgui::Button::Ptr> & getLvlButtons();
	//TexTBox z liczb� krok�w i etapem - boczne menu
	tgui::TextBox::Ptr getSteps();
	//Label z liczb� krok�w w menu wygranej
	tgui::Label::Ptr getStepsTextBox();
	//TileMap t�o dla menu g�ownego
	TileMap getTheme();
	//TileMap t�o dla menu wyboru etap�w
	TileMap getbTheme();
	//rysuje menu g�owne
	void drawMain();
	//rysuje boczne menu
	void drawSide();
	//rusyje menu edycji
	void drawEdit();
	//rysuje menu wyboru etap�w
	void drawLvl();
	//rysuje menu wygranej
	void drawWin();
	//zwraca aktualny etap
	int getLvl();
};

