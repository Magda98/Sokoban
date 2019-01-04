#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "Player.h"
#include "EndPoint.h"
#include "Box.h"
#include "TileMap.h"

/*!
*	\brief klasa MapCreator
*
*	Klasa odpowiadaj�ca za tworzenie oraz edycj� map
*/
class MapCreator : public Entity
{
private:
	sf::Texture sokoban;/*!< Tekstura*/
	std::vector<int> level_c;/*!< Vector int'�w opisuj�cy poziom*/
	Player pl_c;/*!< obiekt typu Player*/
	std::ofstream myfile;/*!< Obs�uga pliku z mapami*/
	std::vector<int> ep_c;/*!< Vector zawieraj�cy pozycj� punkt�w ko�cowych*/
	std::vector<int> bx_c;/*!< Vector zawieraj�cy pozycj� skrzynek*/
	Entity preview;/*!< obekt typu Entity, podgl�d aktulanie wybranego elementu w kreatorze map*/
	TileMap map_c;/*!< Obiekt mapy tworzonej przez gracza*/
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

