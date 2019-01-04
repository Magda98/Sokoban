#include "MapCreator.h"


/*!
*	\brief Ustawia odpowiednio pocz�tkowe warto�ci p�l sk�adowych, ustawia tekstur�
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
*	\brief Ustawia odpowiedni� tekstur� w danym miejscu mapy
*
*	Ustawia wybran� tekstur�, w miejscu klikni�cia lewym przyciskiem myszy przez gracza, nast�pnie tworzy map� gotow� do narysowania w oknie
*
*	\param[in] position pozycja w kt�rej znajdowa� si� kursor podczas klikni�cia mysz�
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
*	Zapisuje poziom w pliku, najpierw warstwa mapy, po�niej wsp�rz�dne postaci gracza, nast�pnie ilo�� skrzynek, pozycje skrzynek oraz pozycje punkt�w ko�cowych 
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
*	\brief Pobiera pozycj� postaci gracza
*
*	\return pozycja postaci gracza
*/
sf::Sprite MapCreator::getPl()
{
	return pl_c.getSprite();
}

/*!
*	\brief Ustawia odpowiedni� pozycj�postaci gracza
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
*	\brief Zapisuje odpowiednie pozycje punkt�w ko�cowych w vectorze
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
*	\brief Tworzy map�
*
*	Tworzy map� z vectora int'�w level_c, u�ywaj�� metody z klasy TileMap
*/
void MapCreator::createTmap()
{
	map_c.load(sokoban, sf::Vector2u(width, height), level_c, 13, 10);
}

/*!
*	\brief Zwraca obiekt klasy TileMap, aby narysowa� map� w oknie
*
*	\return obiekt TileMap map_c
*/
TileMap MapCreator::getTmap()
{
	return map_c;
}
/*!
*	\brief	Ustawia odpowiedni� tekstur� w podgl�dzie
*
*	\param[in] crea zewn�trzny licznik, kt�ry jest inkrementowany lub dekrementowany przy u�yciu Scrolla lub klawisza 'p'
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
*	\brief	Pobiera Sprite'a podgl�du aby mo� go narysowa� w oknie
*
*	\return Sprite podgl�du
*/
sf::Sprite MapCreator::getPreview()
{
	return preview.getSprite();
}
/*!
*	\brief	Zapisuje edytowany etap w pliku tekstowym
*
*	Tworzy nowy plik tekstowy zmienij�c odpowidni� lini�,
*	Zapisuje poziom w pliku, najpierw warstwa mapy, po�niej wsp�rz�dne postaci gracza, nast�pnie ilo�� skrzynek, pozycje skrzynek oraz pozycje punkt�w ko�cowych 
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
*	\brief Resetuje odpowiednie pola sk�adowe 
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

