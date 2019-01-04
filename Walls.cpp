#include "Walls.h"

/*!
*	\brief Tworzy œciany
*
*	tworzy vector o danej wielkoœci, ustawia pust¹ teksturê Sprite'a, potrzebne do wykrywania kolizji
*
*	\param[in] array vector opicuj¹cy dan¹ mapê
*
*	\return vector obiektów typu Sprite
*/
std::vector<sf::Sprite> Walls::CreateWalls(std::vector<int> array)
{
	sf::Texture texture;
	texture.create(width, height);
	int ile = 0;
	for (int i = 0; i < 130; ++i)
	{
		if (array[i] == 0)
		{
			ile++;
		}

	}
	std::vector<sf::Sprite> wall(ile);
	int j = 0;

	for (int i = 0; i < 130; i++)
	{
		if (array[i] == 0)
		{
			sf::Sprite s;
			s.setPosition(sf::Vector2f((float)(i % 13)*width,(float) (i / 13)*height));
			s.setTexture(texture);
			wall.push_back(s);
		}
	}
	return wall;
}
