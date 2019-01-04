#include "Entity.h"



/*!
*	 \brief ustawia odpowiedni¹ pozyjcê na mapie
*
*	ustawia odpowiednio sk³adow¹ x oraz sk³adow¹ y danego obiektu.
*
*	\param[in] x sk³adowa pozioma
*	\param[in] y sk³adowa pionowa
*/
void Entity::setPosition(int x, int y)
{
	sprite.setPosition((float)width * x, (float)height * y);
	this->x = x;
	this->y = y;
}
/*!
*	\brief zwraca sprite'a danego obiektu
*
*	\return sprite obiektu
*/
sf::Sprite Entity::getSprite()
{
	return sprite;
}
/*!
*	\brief zwraca sk³adow¹ pionow¹ pozycji
*
*	\return sk³adowa y
*/
int Entity::getYpos()
{
	return y;
}
/*!
*	\brief	zwraca sk³adow¹ pioziom¹ pozycji
*
*	\return sk³adowa x
*/
int Entity::getXpos()
{
	return x;
}
/*!
*	\brief przesuwa obiekt o podany wektor wzglêdem aktualnej pozycji
*
*	\param[in] width o ile px wzglêdêm aktualnej pozycji przesun¹æ obiekt w poziomie
*	\param[in] height o ile px wzglêdem aktualnej pozycji przesun¹æ obiekt w pionie
*/
void Entity::Move(int width, int height)
{
	sprite.move(sf::Vector2f((float)width,(float) height));
	this->x = sprite.getPosition().x;
	this->y = sprite.getPosition().y;
}
/*!
* \brief ustawia odpowiedni¹ teksturê
*
*	metoda ustawia odpowiedni¹ teksturê
*/
void Entity::setTex( int nm, sf::Texture &sokoban) 
{
	sprite.setTexture(sokoban);
	sprite.setTextureRect(sf::IntRect(nm*width, 0, width, height));
}

