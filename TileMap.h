#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Tile.h"

class TileMap :  public Entity
{
public:

	bool load(sf::Texture &sokobanTexture, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int calcWidth, unsigned int calcHeight);
	void drawMap(sf::RenderWindow &window);
private:
	sf::VertexArray vertices;
	sf::Texture sokoban;
};

