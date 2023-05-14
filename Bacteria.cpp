#include "Bacteria.h"
#include "Map.h"
#include "Enemy.h"
#include <iostream>

void Bacteria::initVariables()
{
	this->speed = 10.f;
	this->hpMax = 4;
	this->hp = this->hpMax;
	this->damage = 1;
	this->gold = 15;
}

void Bacteria::initTexture()
{
	if (!this->texture.loadFromFile("Textures/bacteria.png"))
	{
		std::cout << "ERROR::ENEMY::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
}

void Bacteria::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(sf::Vector2f(20.f, 20.f));
	this->sprite.setColor(sf::Color::Black);
}

Bacteria::Bacteria()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Bacteria::Bacteria(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
    this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

Bacteria::~Bacteria()
{
}

void Bacteria::update(Map& map, int x, int y)
{
    
}


void Bacteria::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
