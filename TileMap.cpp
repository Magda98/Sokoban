#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "TileMap.h"


bool TileMap:: load(sf::Texture &sokobanTexture, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int calcWidth, unsigned int calcHeight)
{
	{
		sokoban = sokobanTexture;
		// resize the vertex array to fit the level size
		vertices.setPrimitiveType(sf::Quads);
		vertices.resize(calcWidth * calcHeight * 4);

		// populate the vertex array, with one quad per tile
		for (unsigned int i = 0; i < calcWidth; ++i)
			for (unsigned int j = 0; j < calcHeight; ++j)
			{
				// get the current tile number
				int tileNumber = tiles[i + j * calcWidth];

				// find its position in the sokobanTexture texture
				int tu = tileNumber % (sokobanTexture.getSize().x / tileSize.x);
				int tv = tileNumber / (sokobanTexture.getSize().x / tileSize.x);

				// get a pointer to the current tile's quad
				sf::Vertex* quad = &vertices[(i + j * calcWidth) * 4];

				// define its 4 corners
				quad[0].position = sf::Vector2f((float)i * tileSize.x, (float)j * tileSize.y);
				quad[1].position = sf::Vector2f((float)(i + 1) * tileSize.x, (float)j * tileSize.y);
				quad[2].position = sf::Vector2f((float)(i + 1) * tileSize.x, (float)(j + 1) * tileSize.y);
				quad[3].position = sf::Vector2f((float)i * tileSize.x, (float)(j + 1) * tileSize.y);

				// define its 4 texture coordinates
				quad[0].texCoords = sf::Vector2f((float)tu * tileSize.x, (float)tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((float)(tu + 1) * tileSize.x, (float)tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((float)(tu + 1) * tileSize.x, (float)(tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f((float)tu * tileSize.x, (float)(tv + 1) * tileSize.y);
			}

		return true;
	}
}

void TileMap::drawMap(sf::RenderWindow &window)
{
	window.draw(vertices, &sokoban);
}

