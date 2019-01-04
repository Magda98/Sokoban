#include "Game.h"

/*!
*	\brief konstruktor z parametrem
*
*
*	Ustawiana jest tekstura, oraz ustawiane s¹ odpowienie pola sk³adowe
*
*	\param[in,out] sokoban tekstura
*/
Game::Game(sf::Texture & sokoban)
{
	this->sokoban = sokoban;
	pl.setTex(4, sokoban);
	level = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
	};
	steps = 0;
}
/*!
*	\brief	Tworzy vector œcian
*
*	Tworzy vector œcian na podstawie mapy danego poziomu(vectora int'ów), nastêpnie ustawia w obiekcie typu Player œciany 
*/
void Game::createWalls()
{
	std::vector<sf::Sprite> x = walls.CreateWalls(level);
	pl.setWall(x);
}
/*!
*	\brief Stworzenie odpowiedniej mapy graficznie, na podstawie danych o poziomie z vector'a int'ów
*/
void Game::loadTilemap()
{
	map.load(sokoban, sf::Vector2u(map.width, map.height), level, 13, 10);
}

/*!
*	\brief Wyzerowanie oraz wyczyszczenie odpowiednich pól sk³adowych
*/
void Game::clearlvl()
{
	steps = 0;
	bx.clear();
	ep.clear();
	pl.setTex(4, sokoban);
}

/*!
*	\brief Zwraca Sprite'a postaci gracza
*
*	\return pl Sprit'e
*/
sf::Sprite Game::getPlayer()
{
	return pl.getSprite();
}
/*!
*	\brief Zwraca obiekt typu TileMap
*
*	\return map
*/
TileMap Game::getTmap()
{
	return map;
}
/*!
*	\brief Zwraca vector Sprite'ów skrzynek
*
*	\return Sprite'y skrzynek
*/
std::vector<sf::Sprite> Game::getBox()
{

	std::vector<sf::Sprite> sbox;
	for (auto b : bx)
	{
		sbox.push_back(b.getSprite());
	}
	return sbox;
}

/*!
*	\brief Zwraca vector Sprite'ów punktów koñcowych
*
*	\return Sprite'y punktów koñcowych
*/
std::vector<sf::Sprite> Game::getEndPoint()
{
	std::vector<sf::Sprite> sep;
	for (auto e : ep)
	{
		sep.push_back(e.getSprite());
	}
	return sep;
}
/*!
*	\brief Wczytuje odpowiedni poziom
*
*	Wczytuje odpowieni poziom z pliku tekstowego, zapisuje informacje do vectora int'ów - level,
*	ustawia pozycjê gracza, wczytuje skrzynki i punkty koñcowe do odpowiednich vector'ów
*
*	\param[in] x poziom
*/
void Game::loadLvl(int x) {
	std::ifstream mapFile("map.txt");
	std::string line;
	for (int i = 1; i <= x; i++)
	{

		if (i == x)
		{
			int num, x, y;
			for (int j = 0; j < 130; j++) {
				mapFile >> num;
				level[j] = num;
			}
			mapFile >> x;
			mapFile >> y;
			pl.setPosition(x, y);
			mapFile >> num;
			for (int k = 0; k < num; k++) {
				Box *element = new Box();
				mapFile >> x;
				mapFile >> y;
				(*element).setTex(20, sokoban);
				(*element).setPosition(x, y);
				bx.push_back(*element);
			}
			for (int k = 0; k < num; k++) {
				EndPoint *element = new EndPoint();
				mapFile >> x;
				mapFile >> y;
				(*element).setTex(24, sokoban);
				(*element).setPosition(x, y);
				ep.push_back(*element);
			}

			break;
		}
		getline(mapFile, line);

	}
	mapFile.close();
	createWalls();
	loadTilemap();
}

/*!
*	\brief	porusza postaæ gracza o jedno pole w górê, wykorzystuje metodê klasy Player
*/
void Game::moveUp()
{
	pl.move_up(bx, sokoban, steps);
}
/*!
*	\brief	porusza postaæ gracza o jedno pole w dó³, wykorzystuje metodê klasy Player
*/
void Game::moveDown()
{
	pl.move_down(bx, sokoban, steps);
}
/*!
*	\brief	porusza postaæ gracza o jedno pole w prawo, wykorzystuje metodê klasy Player
*/
void Game::moveRight()
{
	pl.move_right(bx, sokoban, steps);
}
/*!
*	\brief	porusza postaæ gracza o jedno pole w lewo, wykorzystuje metodê klasy Player
*/
void Game::moveLeft()
{
	pl.move_left(bx, sokoban, steps);
}
/*!
*	\brief	zlicza liczbê etapów z pliku tekstowego, pojedyncza linia to poziom
*/
int Game::getLvlcount()
{
	int ile = 0;
	std::string x;
	std::ifstream mapFile("map.txt");
	while (!mapFile.eof()) {
		std::getline(mapFile, x);
		ile++;
	}
	return ile-1;
}

/*!
*	\brief	zwraca liczbê kroków wykonanych przez gracza
*/
int Game::getSteps()
{
	return steps;
}
/*!
*	\brief	Usuwa dany poziom
*
*	Usuwa dany poziom - tworzy nowy plik w którym linia z danym poziomem zostaje pominiêta
*/
void Game::deleteLvl(int x, int lvl)
{
	std::ifstream mapFile("map.txt");
	std::ofstream temp;
	temp.open("temp.txt");
	std::string line;
	for (int i = 1; i <= lvl; ++i)
	{
		getline(mapFile, line);
		if (i != x)
		{
			temp << line << std::endl;
		}

	}
	mapFile.close();
	temp.close();
	remove("map.txt");
	rename("temp.txt", "map.txt");
}
/*!
*	\brief	Sprawdza czy skrzynki znajduj¹ siê na punktach koñcowcyh
*
*	Je¿eli skrzynki znajduj¹ siêna punktach koñcowcyh, ustawia stan gry na dany
*
*	\param[in,out] gameState dany stan gry
*/
void Game::checkIfWin(int &gameState) {
	int count = 0;
	for (auto &b : bx) {
		int wew = 0;
		for (auto e : ep)
		{
			if (e.getSprite().getPosition().x == b.getSprite().getPosition().x  && e.getSprite().getPosition().y == b.getSprite().getPosition().y)
			{
				count++;
				b.setTex(21, sokoban);
				wew++;
			}
			else if (wew != 1) {
				b.setTex(20, sokoban);
			}
		}
	}
	if (count == bx.size())
		gameState = 4;
}
