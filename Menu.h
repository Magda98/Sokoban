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
	tgui::Gui step;
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
	tgui::Gui gui;
public:
	Menu(sf::RenderWindow &window, tgui::Theme &theme, sf::Texture &sokoban);
	void createSteps(sf::RenderWindow &window);
	void setMainEventHandler(sf::Event &event);
	void setSideEventHandler(sf::Event & event);
	void setLvlEventHandler(sf::Event & event);
	void setWinEventHandler(sf::Event & event);
	void setEditEventHandler(sf::Event & event);
	void createButtons(int lvl);
	void setLvl(int x);
	std::vector<tgui::Widget::Ptr> getMainWidget();
	std::vector<tgui::Widget::Ptr> getSideWidget();
	std::vector<tgui::Widget::Ptr> getWinWidget();
	std::vector<tgui::Widget::Ptr>  getEditButtons();
	std::vector<tgui::Button::Ptr> & getLvlButtons();
	tgui::TextBox::Ptr getSteps();
	TileMap getTheme();
	TileMap getbTheme();
	void drawGui();
	void drawMain();
	void drawSide();
	void drawEdit();
	void drawLvl();
	void drawWin();
	void drawStep();
	int getLvl();
};

