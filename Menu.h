#pragma once
#include <TGUI/TGUI.hpp>
#include <fstream>
#include <iostream>
#include "TileMap.h"
class Menu
{
private:
	sf::Texture sokoban;
	tgui::Gui main;
	tgui::Gui side;
	tgui::Gui chooseLvl;
	tgui::Gui win;
	tgui::Gui edit;
	tgui::Theme theme;
	std::vector<tgui::Widget::Ptr> mainWidget;
	std::vector<tgui::Widget::Ptr> winWidget;
	std::vector<tgui::Widget::Ptr> sideWidget;
	std::vector<tgui::Widget::Ptr> editWidget;
	std::vector<int> menuTheme;
	std::vector<int> buttonTheme;
	TileMap bTheme;
	TileMap mTheme;
	void getWidgetlist();
	int lvl;
	std::vector<tgui::Button::Ptr> lvList;
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

