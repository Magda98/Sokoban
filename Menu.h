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

