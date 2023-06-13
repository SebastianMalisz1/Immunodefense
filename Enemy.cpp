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

void Enemy::loseHp(const int value) {
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void Enemy::upgrade()
{
	this->hpMax = 100;
}

void Enemy::upgrade2()
{
	this->hpMax = 200;
}

void Enemy::upgrade3()
{
	this->hpMax = 300;
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

