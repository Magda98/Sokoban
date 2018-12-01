#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "TileMap.h"


bool TileMap:: load(sf::Texture &sokobanTexture, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int calcWidth, unsigned int calcHeight)
{
	{
		sokoban = sokobanTexture;
		// ustawia liczbê wierzcho³ków dla danej mapy
		vertices.setPrimitiveType(sf::Quads);
		vertices.resize(calcWidth * calcHeight * 4);

		for (unsigned int i = 0; i < calcWidth; ++i)
			for (unsigned int j = 0; j < calcHeight; ++j)
			{
				// aktualny numer Tile'a
				int tileNumber = tiles[i + j * calcWidth];

				// ustawia odpowiedni nr(w wierszu) tekstury z sokoban.png
				int tu = tileNumber % (sokobanTexture.getSize().x / tileSize.x);
				//tv = 0 (jest to nr w kolumnie) poniewa¿ sokoban.png ma jest zapisana w jednej linii
				int tv = 0; 

				// quad to odpowiednie wierzcho³ki kwadratu
				sf::Vertex* quad = &vertices[(i + j * calcWidth) * 4];

				// ustawia 4 wierzcho³ki kwadratu w odpowiednie pozyjce na mapie
				quad[0].position = sf::Vector2f((float)i * tileSize.x, (float)j * tileSize.y);
				quad[1].position = sf::Vector2f((float)(i + 1) * tileSize.x, (float)j * tileSize.y);
				quad[2].position = sf::Vector2f((float)(i + 1) * tileSize.x, (float)(j + 1) * tileSize.y);
				quad[3].position = sf::Vector2f((float)i * tileSize.x, (float)(j + 1) * tileSize.y);

				// ustawia odpowiednie wspo³rzêdne tekstury
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

