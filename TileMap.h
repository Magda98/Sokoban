#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Tile.h"

/*!
*	\brief klasa TileMap
*
*	Tworzy t�o oraz t�o map
*/
class TileMap :  public Entity
{
public:
	//tworzy VertexArray dla ca�ej mapy o wymiarach Tile::width x Tile::height, ustawiaj�c odpowiedni� tekstur� w czworok�ty
	void load(sf::Texture &sokobanTexture, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int calcWidth, unsigned int calcHeight);
	//rysuje map�
	void drawMap(sf::RenderWindow &window);
private:
	sf::VertexArray vertices;/*!< VertexArray zawieraj�cy informacj� o wierzcho�kach*/
	sf::Texture sokoban;/*!< tekstura*/
};

