#include "Entity.h"



/*!
*	 \brief ustawia odpowiedni� pozyjc� na mapie
*
*	ustawia odpowiednio sk�adow� x oraz sk�adow� y danego obiektu.
*
*	\param[in] x sk�adowa pozioma
*	\param[in] y sk�adowa pionowa
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
*	\brief zwraca sk�adow� pionow� pozycji
*
*	\return sk�adowa y
*/
int Entity::getYpos()
{
	return y;
}
/*!
*	\brief	zwraca sk�adow� pioziom� pozycji
*
*	\return sk�adowa x
*/
int Entity::getXpos()
{
	return x;
}
/*!
*	\brief przesuwa obiekt o podany wektor wzgl�dem aktualnej pozycji
*
*	\param[in] width o ile px wzgl�d�m aktualnej pozycji przesun�� obiekt w poziomie
*	\param[in] height o ile px wzgl�dem aktualnej pozycji przesun�� obiekt w pionie
*/
void Entity::Move(int width, int height)
{
	sprite.move(sf::Vector2f((float)width,(float) height));
	this->x = sprite.getPosition().x;
	this->y = sprite.getPosition().y;
}
/*!
* \brief ustawia odpowiedni� tekstur�
*
*	metoda ustawia odpowiedni� tekstur�
*/
void Entity::setTex( int nm, sf::Texture &sokoban) 
{
	sprite.setTexture(sokoban);
	sprite.setTextureRect(sf::IntRect(nm*width, 0, width, height));
}

