#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Tile.h"

/*!
*	\brief klasa TileMap
*
*	Tworzy t³o oraz t³o map
*/
class TileMap :  public Entity
{
public:
	//tworzy VertexArray dla ca³ej mapy o wymiarach Tile::width x Tile::height, ustawiaj¹c odpowiedni¹ teksturê w czworok¹ty
	void load(sf::Texture &sokobanTexture, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int calcWidth, unsigned int calcHeight);
	//rysuje mapê
	void drawMap(sf::RenderWindow &window);
private:
	sf::VertexArray vertices;/*!< VertexArray zawieraj¹cy informacjê o wierzcho³kach*/
	sf::Texture sokoban;/*!< tekstura*/
};

