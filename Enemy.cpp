#include "Enemy.h"
#include <iostream>

void Enemy::initVariables()
{
	this->speed = 10.f;
	this->hpMax = 10;
	this->hp = this->hpMax;
	this->damage = 0;
	this->gold = 0;
}

void Enemy::initTexture()
{
	if (!this->texture.loadFromFile("Textures/bacteria.png"))
	{
		std::cout << "ERROR::ENEMY::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
}

void Enemy::initSprite()
{
	this->sprite.setTexture(this->texture);
}

Enemy::Enemy()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->sprite.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	this->sprite.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
