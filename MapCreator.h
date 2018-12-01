#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "Player.h"
#include "EndPoint.h"
#include "Box.h"
#include "TileMap.h"
class MapCreator : public Entity
{
private:
	sf::Texture sokoban;
	std::vector<int> level_c;
	Player pl_c;
	std::ofstream myfile;
	std::vector<int> ep_c;
	std::vector<int> bx_c;
	Entity preview;
	TileMap map_c;
	void BxPosition();
	void EpPosition();
	void createTmap();
public:
	MapCreator(sf::Texture &sokoban);
	//zapisuje edytowany etap spowotem do pliku txt
	void saveEditLvl(int lvl, int x);
	//wczytuje etap do edycji
	void loadLvl(int lvl);
	//zapisuje nowo stworzony etap
	void SaveLvl();
	//czy�ci map� kreatora ustawiaj�c j� na pocz�tkowe warto�ci
	void clearMp();
	//ustwia podgl�d aktualnie wybranego elementu
	void setPreview(int x);
	//ustawia na mapie kreatora wybrany element
	void SetMap(sf::Vector2i position, int tile = 0);
	//ustawia na mapie kreatora gracza
	void PlPosition(sf::Vector2i position);
	//zwraca TileMap kreatora aby m�c j� narysowa�
	TileMap getTmap();
	//zwraca Sprite'a podgl�du aby m�c go naryswoa�
	sf::Sprite getPreview();
	//zwraca Sprite'a gracza aby m�c go naryswoa�
	sf::Sprite getPl();
};

