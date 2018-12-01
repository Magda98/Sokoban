#include "Entity.h"




void Entity::setPosition(int x, int y)
{
	sprite.setPosition((float)64 * x, (float)64 * y);
	this->x = x;
	this->y = y;
}
sf::Sprite Entity::getSprite()
{
	return sprite;
}
int Entity::getYpos()
{
	return y;
}
int Entity::getXpos()
{
	return x;
}
void Entity::Move(int width, int height)
{
	sprite.move(sf::Vector2f((float)width,(float) height));
}
void Entity::setTex( int nm, sf::Texture &sokoban) 
{
	sprite.setTexture(sokoban);
	sprite.setTextureRect(sf::IntRect(nm*width, 0, width, height));
}

