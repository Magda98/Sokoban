#include "Menu.h"



Menu::Menu(sf::RenderWindow &window, tgui::Theme &theme, sf::Texture &sokoban)
{

	main.setTarget(window);
	side.setTarget(window);
	chooseLvl.setTarget(window);
	win.setTarget(window);
	edit.setTarget(window);

	this->theme = theme;

	main.loadWidgetsFromFile("menu.txt");
	side.loadWidgetsFromFile("back.txt");
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
	mTheme.load(sokoban, sf::Vector2u(64, 64), menuTheme, 13, 10);
	bTheme.load(sokoban, sf::Vector2u(64, 64), buttonTheme, 13, 10);
	getWidgetlist();

	lvl = 1;

	createSteps(window);

}

void Menu::createSteps(sf::RenderWindow & window)
{
	tgui::TextBox::Ptr stepsTxt = tgui::TextBox::create();
	gui.setTarget( window );
	stepsTxt->setPosition(680, 83);
	stepsTxt->setSize(120, 120);
	stepsTxt->setTextSize(18);
	stepsTxt->setRenderer(theme.getRenderer("TextBox"));
	stepsTxt->isReadOnly();
	gui.add(stepsTxt, "steps");
}

void Menu::getWidgetlist()
{
	mainWidget = main.getWidgets();
	sideWidget = side.getWidgets();
	winWidget = win.getWidgets();
	editWidget = edit.getWidgets();
}


void Menu::setMainEventHandler(sf::Event & event)
{
	main.handleEvent(event);
}
void Menu::setSideEventHandler(sf::Event & event)
{
	side.handleEvent(event);
}
void Menu::setLvlEventHandler(sf::Event & event)
{
	chooseLvl.handleEvent(event);
}
void Menu::setWinEventHandler(sf::Event & event)
{
	win.handleEvent(event);
}
void Menu::setEditEventHandler(sf::Event & event)
{
	edit.handleEvent(event);
}
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
		button->setPosition((i % 11) * 64 + 71, (i / 11) * 64 + 71);
		button->setText(std::to_string(i + 1));
		lvList.push_back(button);
	}
	for (const auto& bt : lvList) {
		chooseLvl.add(bt);
	}
}

std::vector<tgui::Widget::Ptr> Menu::getMainWidget()
{
	return mainWidget;
}

std::vector<tgui::Widget::Ptr> Menu::getSideWidget()
{
	return  sideWidget;
}

std::vector<tgui::Widget::Ptr> Menu::getWinWidget()
{
	return winWidget;
}

std::vector<tgui::Button::Ptr> & Menu::getLvlButtons()
{
	return lvList;
}

tgui::TextBox::Ptr Menu::getSteps()
{
	return	gui.get<tgui::TextBox>("steps");
}

std::vector<tgui::Widget::Ptr>  Menu::getEditButtons()
{
	return editWidget;
}


TileMap Menu::getTheme()
{
	return mTheme;
}

TileMap Menu::getbTheme()
{
	return bTheme;
}

void Menu::drawGui()
{
	gui.draw();
}

void Menu::setLvl(int x)
{
	lvl = x;
}

void Menu::drawMain()
{
	main.draw();
}

void Menu::drawSide()
{
	side.draw();
}

void Menu::drawEdit()
{
	edit.draw();
}

void Menu::drawLvl()
{
	chooseLvl.draw();
}

void Menu::drawWin()
{
	win.draw();
}

void Menu::drawStep()
{
	step.draw();
}

int Menu::getLvl()
{
	return lvl;
}

