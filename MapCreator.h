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
*	Klasa odpowiadaj¹ca za tworzenie oraz edycjê map
*/
class MapCreator : public Entity
{
private:
	sf::Texture sokoban;/*!< Tekstura*/
	std::vector<int> level_c;/*!< Vector int'ów opisuj¹cy poziom*/
	Player pl_c;/*!< obiekt typu Player*/
	std::ofstream myfile;/*!< Obs³uga pliku z mapami*/
	std::vector<int> ep_c;/*!< Vector zawieraj¹cy pozycjê punktów koñcowych*/
	std::vector<int> bx_c;/*!< Vector zawieraj¹cy pozycjê skrzynek*/
	Entity preview;/*!< obekt typu Entity, podgl¹d aktulanie wybranego elementu w kreatorze map*/
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
	//czyœci mapê kreatora ustawiaj¹c j¹ na pocz¹tkowe wartoœci
	void clearMp();
	//ustwia podgl¹d aktualnie wybranego elementu
	void setPreview(int x);
	//ustawia na mapie kreatora wybrany element
	void SetMap(sf::Vector2i position, int tile = 0);
	//ustawia na mapie kreatora gracza
	void PlPosition(sf::Vector2i position);
	//zwraca TileMap kreatora aby móc j¹ narysowaæ
	TileMap getTmap();
	//zwraca Sprite'a podgl¹du aby móc go naryswoaæ
	sf::Sprite getPreview();
	//zwraca Sprite'a gracza aby móc go naryswoaæ
	sf::Sprite getPl();
};

