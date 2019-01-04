#include "Player.h"

/*!
*	\brief Ustawia pole sk�adowe wall 
*/
void Player::setWall(std::vector<sf::Sprite>& w)
{
	wall = w;
}
/*!
*	\brief sprawdza kolizj� postaci gracza ze �cianami
*
*	\return true - kiedy mo�na wykona� ruch, false kiedy nie mo�nago wykona�
*/
bool Player::checkColission(std::vector<sf::Sprite> Swall) {
	bool move = true;
	for (auto wall : Swall) {
		if ((Player::getSprite().getGlobalBounds().intersects(wall.getGlobalBounds())))
		{
			move = false;
		}
	}
	return move;
}

/*!
*	\brief Porusza postaci� gracza w g�r�
*
*	Wykonuje ruch postaci�, je�eli nie jest on mo�liwy posta� wraca na swoje miejsce, nie jest to widoczne w oknie gry, poniewa� podczas wykonywnia tej funkcji okno nie od�wie�a si�
*
*	\param[in,out] bx vector obiekt�w typu Box
*	\param[in,out] sokoban tekstura
*	\param[in,out] step licznik krok�w
*/
void Player::move_up(std::vector<Box> &bx, sf::Texture &sokoban, int & step) {
	setTex(5, sokoban);
	Player::Move(0, -height);
	step++;
	if (!checkColission(wall)) {
		Player::Move(0, height);
		step--;
	}
	for (auto &box : bx) {

		if (Player::getSprite().getGlobalBounds().intersects(box.getSprite().getGlobalBounds()) && box.chechBox(bx, box))
		{
			box.Move(0, -height);
		}
		if (!box.chechBox(bx, box)) {
			Player::Move(0, height);
			box.Move(0, height);
			step--;
		}
		if (!box.checkColission(wall) || !box.chechBox(bx, box)) {
			box.Move(0, height);
			Player::Move(0, height);
			step--;
		}
	}
}

/*!
*	\brief Porusza postaci� gracza w d�
*
*	Wykonuje ruch postaci�, je�eli nie jest on mo�liwy posta� wraca na swoje miejsce, nie jest to widoczne w oknie gry, poniewa� podczas wykonywnia tej funkcji okno nie od�wie�a si�
*
*	\param[in,out] bx vector obiekt�w typu Box
*	\param[in,out] sokoban tekstura
*	\param[in,out] step licznik krok�w
*/
void Player::move_down(std::vector<Box> &bx, sf::Texture &sokoban, int & step) {
	setTex(4, sokoban);
	Player::Move(0, height);
	step++;
	if (!checkColission(wall)) {
		Player::Move(0, -height);
		step--;
	}
	for (auto &box : bx) {
		if (Player::getSprite().getGlobalBounds().intersects(box.getSprite().getGlobalBounds()) && box.chechBox(bx, box))
		{
			box.Move(0, height);
		}
		if (!box.chechBox(bx, box)) {
			Player::Move(0, -height);
			box.Move(0, -height);
			step--;
		}
		if (!box.checkColission(wall) || !box.chechBox(bx, box)) {
			box.Move(0, -height);
			Player::Move(0, -height);
			step--;
		}
	}
}

/*!
*	\brief Porusza postaci� gracza w lewo
*
*	Wykonuje ruch postaci�, je�eli nie jest on mo�liwy posta� wraca na swoje miejsce, nie jest to widoczne w oknie gry, poniewa� podczas wykonywnia tej funkcji okno nie od�wie�a si�
*
*	\param[in,out] bx vector obiekt�w typu Box
*	\param[in,out] sokoban tekstura
*	\param[in,out] step licznik krok�w
*/
void Player::move_left(std::vector<Box> &bx, sf::Texture &sokoban, int & step) {
	setTex(2, sokoban);
	Player::Move(-width, 0);
	step++;
	if (!checkColission(wall)) {
		Player::Move(width, 0);
		step--;
	}
	int k = 0;
	for (auto &box : bx) {
		if (Player::getSprite().getGlobalBounds().intersects(box.getSprite().getGlobalBounds()) && box.chechBox(bx, box))
		{
			box.Move(-width, 0);
		}
		if (!box.chechBox(bx, box)) {
			Player::Move(width, 0);
			box.Move(width, 0);
			step--;
		}
		if (!box.checkColission(wall) || !box.chechBox(bx, box)) {
			box.Move(width, 0);
			Player::Move(width, 0);
			step--;
		}
	}
}

/*!
*	\brief Porusza postaci� gracza w prawo
*
*	Wykonuje ruch postaci�, je�eli nie jest on mo�liwy posta� wraca na swoje miejsce, nie jest to widoczne w oknie gry, poniewa� podczas wykonywnia tej funkcji okno nie od�wie�a si�
*
*	\param[in,out] bx vector obiekt�w typu Box
*	\param[in,out] sokoban tekstura
*	\param[in,out] step licznik krok�w
*/
void Player::move_right(std::vector<Box> &bx, sf::Texture &sokoban, int & step) {
	setTex(3, sokoban);
	Player::Move(width, 0);
	step++;
	if (!checkColission(wall)) {
		Player::Move(-width, 0);
		step--;
	}
	int k = 0;
	for (auto &box : bx) {
		if (Player::getSprite().getGlobalBounds().intersects(box.getSprite().getGlobalBounds()) && box.chechBox(bx, box))
		{
			box.Move(width, 0);
		}
		if (!box.chechBox(bx, box)) {
			Player::Move(-width, 0);
			box.Move(-width, 0);
			step--;
		}
		if (!box.checkColission(wall) || !box.chechBox(bx, box)) {
			box.Move(-width, 0);
			Player::Move(-width, 0);
			step--;
		}
	}
}