#include "Enemy.h"
#include <iostream>

//void Enemy::initVariables()
//{
//	this->speedX = 0.f;
//	this->speedY = 0.f;
//	this->hpMax = 0;
//	this->hp = this->hpMax;
//	this->damage = 0;
//	this->gold = 0;
//}
//
//void Enemy::initTexture()
//{
//	if (!this->texture.loadFromFile("Textures/bacteria.png"))
//	{
//		std::cout << "ERROR::ENEMY::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
//	}
//}
//
//void Enemy::initSprite()
//{
//	this->sprite.setTexture(this->texture);
//}

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


void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

