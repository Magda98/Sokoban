#pragma once
#include <SFML/Graphics.hpp>
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
	void saveEditLvl(int lvl, int x);
	void loadLvl(int lvl);
	void SaveLvl();
	void clearMp();
	void setPreview(int x);
	void SetMap(sf::Vector2i position, int tile = 0);
	void PlPosition(sf::Vector2i position);
	TileMap getTmap();
	sf::Sprite getPreview();
	sf::Sprite getPl();
	std::vector<int> getLvl();
};

