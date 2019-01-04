#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "TileMap.h"

/*!
*	\brief	odpowiada za tworzenie t³a/mapy
*
*	Tworzy tabelê wierzcho³ków kwadratów, ustawiaj¹c po kolei ich pozycje w oknie, nastêpnie ustawia koordynaty tekstury
*
*	\param[in,out] sokobanTexture tekstura
*	\param[in] tileSize wielkoœæ jednego tile'a
*	\param[in] tiles vector opisuj¹cy wygl¹d mapy/t³a
*	\param[in] calcWidth obliczona szerokoœæ mapy 
*	\param[in] calcHeight obliczona szerokoœæ mapy
*/
void TileMap:: load(sf::Texture &sokobanTexture, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int calcWidth, unsigned int calcHeight)
{

	sokoban = sokobanTexture;
	// ustawia liczbê wierzcho³ków dla danej mapy
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(calcWidth * calcHeight * 4);

	for(unsigned int i = 0; i < tiles.size(); ++i)
	{
		// aktualny numer Tile'a z wektora
		int tileNumber = tiles[i];
		// ustawia 4 wierzcho³ki kwadratu w odpowiednie pozyjce na mapie
		vertices[i * 4].position = sf::Vector2f(float((i%13) * tileSize.x),float(i/13 * tileSize.y));
		vertices[i * 4 + 1].position = sf::Vector2f(float((i%13 +1) * tileSize.x),float( i/13 * tileSize.y));
		vertices[i * 4 + 2].position = sf::Vector2f(float((i%13 +1) * tileSize.x),float((i/13 +1) * tileSize.y));
		vertices[i * 4 + 3].position = sf::Vector2f(float((i%13) * tileSize.x),float((i/13 +1) * tileSize.y));
		// ustawia odpowiednie wspo³rzêdne tekstury
		vertices[i * 4].texCoords = sf::Vector2f(float(tileNumber * tileSize.x), 0);
		vertices[i * 4 + 1].texCoords = sf::Vector2f(float((tileNumber + 1) * tileSize.x), 0);
		vertices[i * 4 + 2].texCoords = sf::Vector2f(float((tileNumber + 1) * tileSize.x), float(tileSize.y));
		vertices[i * 4 + 3].texCoords = sf::Vector2f(float(tileNumber * tileSize.x), float(tileSize.y));
	}
}
/*!
*	\brief	Rysuje mapê/t³o w oknie
*
*	\param[in,out] window okno gry
*/
void TileMap::drawMap(sf::RenderWindow &window)
{
	window.draw(vertices, &sokoban);
}

