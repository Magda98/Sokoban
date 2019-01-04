#include "MapCreator.h"


/*!
*	\brief Ustawia odpowiednio pocz¹tkowe wartoœci pól sk³adowych, ustawia teksturê
*
*	\param[in,out] sokoban tekstura
*/
MapCreator::MapCreator(sf::Texture &sokoban) {
	level_c = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10,
	};
	this->sokoban = sokoban;
	createTmap();
	pl_c.setTex(4, sokoban);
	pl_c.setPosition(-1, -1);
	preview.setTex(0, sokoban);
	preview.setPosition(11, 2);
}

/*!
*	\brief Ustawia odpowiedni¹ teksturê w danym miejscu mapy
*
*	Ustawia wybran¹ teksturê, w miejscu klikniêcia lewym przyciskiem myszy przez gracza, nastêpnie tworzy mapê gotow¹ do narysowania w oknie
*
*	\param[in] position pozycja w której znajdowa³ siê kursor podczas klikniêcia mysz¹
*	\param[in] tile numer odpowiedniej tekstury 
*/
void MapCreator::SetMap(sf::Vector2i position, int tile )
{
	if ((position.x / width + (position.y / height) * 13) >= 0 && (position.x / width + (position.y / height) * 13) <= 129 && position.x < width*9 && width <= position.x && position.y < height*9 && height <= position.y)
		level_c[position.x / width + (position.y / height) * 13] = tile;
	createTmap();
}

/*!
*	\brief	Zapisuje nowo stworzony etap w pliku tekstowym
*
*	Zapisuje poziom w pliku, najpierw warstwa mapy, poŸniej wspó³rzêdne postaci gracza, nastêpnie iloœæ skrzynek, pozycje skrzynek oraz pozycje punktów koñcowych 
*/
void MapCreator::SaveLvl()
{
	EpPosition();
	BxPosition();
	for (auto &lvl : level_c) {
		if (lvl == 20 || lvl == 24)
			lvl = 1;
	}
	sf::Vector2f position;
	myfile.open("map.txt", std::ios_base::app);
	for (auto lvl : level_c) {
		myfile << lvl << " ";
	}
	myfile << pl_c.getXpos() << " " << pl_c.getYpos() << " ";
	myfile << ((bx_c.size()) / 2) << " ";
	for (auto b : bx_c) {
		myfile << b << " ";
	}
	for (auto e : ep_c) {
		myfile << e << " ";
	}
	myfile << "\n";
	myfile.close();
}

/*!
*	\brief Pobiera pozycjê postaci gracza
*
*	\return pozycja postaci gracza
*/
sf::Sprite MapCreator::getPl()
{
	return pl_c.getSprite();
}

/*!
*	\brief Ustawia odpowiedni¹ pozycjêpostaci gracza
*/
void MapCreator::PlPosition(sf::Vector2i position) {
	if (position.x < 9*width && position.x >= width && position.y < 9*height && position.y >= height) {
		pl_c.setPosition(position.x / width, (position.y / height));
	}
}

/*!
*	\brief Zapisuje odpowiednie pozyjce skrznek w vectorze
*/
void MapCreator::BxPosition() {
	for (int i = 0; i < 130; i++) {
		if (level_c[i] == 20) {
			bx_c.push_back(i % 13);
			bx_c.push_back(i / 13);
		}
	}
}

/*!
*	\brief Zapisuje odpowiednie pozycje punktów koñcowych w vectorze
*/
void MapCreator::EpPosition() {
	for (int i = 0; i < 130; i++) {
		if (level_c[i] == 24) {
			ep_c.push_back(i % 13);
			ep_c.push_back(i / 13);
		}
	}
}

/*!
*	\brief Tworzy mapê
*
*	Tworzy mapê z vectora int'ów level_c, u¿ywaj¹æ metody z klasy TileMap
*/
void MapCreator::createTmap()
{
	map_c.load(sokoban, sf::Vector2u(width, height), level_c, 13, 10);
}

/*!
*	\brief Zwraca obiekt klasy TileMap, aby narysowaæ mapê w oknie
*
*	\return obiekt TileMap map_c
*/
TileMap MapCreator::getTmap()
{
	return map_c;
}
/*!
*	\brief	Ustawia odpowiedni¹ teksturê w podgl¹dzie
*
*	\param[in] crea zewnêtrzny licznik, który jest inkrementowany lub dekrementowany przy u¿yciu Scrolla lub klawisza 'p'
*/
void MapCreator::setPreview(int crea)
{
	crea = abs(crea);
	if (crea % 4 == 0)
		preview.setTex(0, sokoban);
	else if (crea % 4 == 1)
		preview.setTex(27, sokoban);
	else if (crea % 4 == 2)
		preview.setTex(25, sokoban);
	else if (crea % 4 == 3)
		preview.setTex(26, sokoban);
}
/*!
*	\brief	Pobiera Sprite'a podgl¹du aby moæ go narysowaæ w oknie
*
*	\return Sprite podgl¹du
*/
sf::Sprite MapCreator::getPreview()
{
	return preview.getSprite();
}
/*!
*	\brief	Zapisuje edytowany etap w pliku tekstowym
*
*	Tworzy nowy plik tekstowy zmienij¹c odpowidni¹ liniê,
*	Zapisuje poziom w pliku, najpierw warstwa mapy, poŸniej wspó³rzêdne postaci gracza, nastêpnie iloœæ skrzynek, pozycje skrzynek oraz pozycje punktów koñcowych 
*/
void MapCreator::saveEditLvl(int lvl, int x)
{
	std::ofstream temp;
	std::string line;
	temp.open("temp.txt");
	EpPosition();
	BxPosition();
	for (auto &lvl : level_c) {
		if (lvl == 20 || lvl == 24)
			lvl = 1;
	}
	sf::Vector2f position;
	std::ifstream myfile("map.txt");
	for (int i = 1; i <= lvl; i++)
	{
		getline(myfile, line);
		if (x == i) {
			for (auto lvl : level_c) {
				temp << lvl << " ";
			}
			temp << pl_c.getXpos() << " " << pl_c.getYpos() << " ";
			temp << ((bx_c.size()) / 2) << " ";
			for (auto b : bx_c) {
				temp << b << " ";
			}
			for (auto e : ep_c) {
				temp << e << " ";
			}
			temp << "\n";
		}
		else{
			temp << line;
			temp << "\n";
		}
	}
	myfile.close();
	temp.close();
	remove("map.txt");
	rename("temp.txt", "map.txt");
}
/*!
*	\brief Wczytuje dany poziom z pliku tekstowego
*
*	Wszystanie poziomu potrzebne podczas edycji poziomu
*/
void MapCreator::loadLvl(int lvl)
{

	std::ifstream mapFile("map.txt");
	std::string line;
	int num, x, y;
	for (int i = 1; i <= lvl; i++)
	{

		if (i == lvl)
		{
			for (int j = 0; j < 130; j++) {
				mapFile >> num;
				level_c[j] = num;
			}
			mapFile >> x;
			mapFile >> y;
			pl_c.setPosition(x, y);

			mapFile >> num;
			for (int j = 0; j < num; j++) {
				mapFile >> x;
				mapFile >> y;
				level_c[y * 13 + x] = 20;
			}
			for (int j = 0; j < num; j++) {
				mapFile >> x;
				mapFile >> y;
				level_c[y * 13 + x] = 24;
			}

		}
		getline(mapFile, line);
	}
	createTmap();
}
/*!
*	\brief Resetuje odpowiednie pola sk³adowe 
*/
void MapCreator::clearMp()
{
	level_c = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 10, 10, 10,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10,
	};
	createTmap();
	ep_c.clear();
	bx_c.clear();

}

