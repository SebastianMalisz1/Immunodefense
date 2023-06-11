#include "Enemy.h"
#include <iostream>



Enemy::Enemy()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}


Enemy::~Enemy()
{
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f Enemy::getPos() const
{
	return this->sprite.getPosition();
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

