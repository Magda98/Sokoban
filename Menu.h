#pragma once
#include <TGUI/TGUI.hpp>
#include <fstream>
#include <iostream>
#include "TileMap.h"
/*!
*	\brief	klasa Manu
*
*	Klasa odpowiedzialna za menu g³owne, menu boczne, menu edytora, menu wygranej
*/
class Menu : public Tile
{
private:
	sf::Texture sokoban;/*!< tekstura*/
	tgui::Gui main;/*!< interfejs menu g³ównego*/
	tgui::Gui side;/*!< interfejs menu bocznego*/
	tgui::Gui chooseLvl;/*!< interfejs menu wyboru etapu*/
	tgui::Gui win;/*!< interfejs menu wygranej*/
	tgui::Gui edit;/*!< interfejs menu edycji*/
	tgui::Theme theme;/*!< motyw menu*/
	std::vector<tgui::Widget::Ptr> mainWidget;/*!< widgety menu g³ównego*/
	std::vector<tgui::Widget::Ptr> winWidget;/*!< widgety menu wygranej*/
	std::vector<tgui::Widget::Ptr> sideWidget;/*!< widgety bocznego menu*/
	std::vector<tgui::Widget::Ptr> editWidget;/*!< widgety menu edycji*/
	std::vector<int> menuTheme;/*!< t³o menu g³ownego*/
	std::vector<int> buttonTheme;/*!< t³o menu wyboru etapu/menu edycji*/
	TileMap bTheme;/*!< TileMap t³a menu wyboru etapu/menu edycji*/
	TileMap mTheme;/*!< TileMap menu g³ównego*/
	int lvl;/*!< przechowuje informacje o liczbie etapów*/
	std::vector<tgui::Button::Ptr> lvList;/*!< vector przechowujacy wskaŸniki do przycisków poziomów*/
	void getWidgetlist();
public:
	Menu(sf::RenderWindow &window, tgui::Theme &theme, sf::Texture &sokoban);
	//ustawia Event dla menu g³ównego
	void setMainEventHandler(sf::Event &event);
	//ustawia Event dla menu bocznego
	void setSideEventHandler(sf::Event & event);
	//ustawia Event dla menu wyboru etapów
	void setLvlEventHandler(sf::Event & event);
	//ustawia Event dla menu po wygranej
	void setWinEventHandler(sf::Event & event);
	//ustawia Event dla menu w edycji map
	void setEditEventHandler(sf::Event & event);
	//tworzy odpowieni¹ liczbê przycisków w zale¿noœci od iloœci etapów wczytanych z pliku
	void createButtons(int lvl);
	//ustawia zmienn¹ z aktualnym etap
	void setLvl(int x);
	//zwraca Widgety menu g³ównego
	std::vector<tgui::Widget::Ptr> getMainWidget();
	//zwraca Widgety menu bocznego
	std::vector<tgui::Widget::Ptr> getSideWidget();
	//zwraca Widgety menu wygranej
	std::vector<tgui::Widget::Ptr> getWinWidget();
	//zwraca Widgety menu edycji
	std::vector<tgui::Widget::Ptr>  getEditButtons();
	//zwraca Widgety menu wyboru etapów
	std::vector<tgui::Button::Ptr> & getLvlButtons();
	//TexTBox z liczb¹ kroków i etapem - boczne menu
	tgui::TextBox::Ptr getSteps();
	//Label z liczb¹ kroków w menu wygranej
	tgui::Label::Ptr getStepsTextBox();
	//TileMap t³o dla menu g³ownego
	TileMap getTheme();
	//TileMap t³o dla menu wyboru etapów
	TileMap getbTheme();
	//rysuje menu g³owne
	void drawMain();
	//rysuje boczne menu
	void drawSide();
	//rusyje menu edycji
	void drawEdit();
	//rysuje menu wyboru etapów
	void drawLvl();
	//rysuje menu wygranej
	void drawWin();
	//zwraca aktualny etap
	int getLvl();
};

