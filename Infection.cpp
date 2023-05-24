#include "Infection.h"

#include <iostream>

void Infection::initVariables()
{
	this->speedX = 0.5f;
	this->speedY = 0.f;
	this->hpMax = 4;
	this->hp = this->hpMax;
	this->damage = 1;
	this->gold = 15;
}

void Infection::initTexture()
{
	//srand(time(NULL));
	//int liczbaLosowa = rand() % 3;
	//std::cout << liczbaLosowa << std::endl;
	//
	if (/*liczbaLosowa == 0 && */!this->texture.loadFromFile("Textures/zielonyWir.png"))
	{
		std::cout << "ERROR::ENEMY::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	/*if (liczbaLosowa == 1 && !this->texture.loadFromFile("Textures/zoltaBak.png"))
	{
		std::cout << "ERROR::ENEMY::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	if (liczbaLosowa == 2 && !this->texture.loadFromFile("Textures/zielonyWir.png"))
	{
		std::cout << "ERROR::ENEMY::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}*/

}

void Infection::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(sf::Vector2f(20.f, 20.f));
	this->sprite.setOrigin(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f);
	/*this->sprite.scale(0.3f, 0.3f);*/
	//this->sprite.setColor(sf::Color::Black);
}



Infection::Infection(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->sprite.setPosition(pos_x, pos_y);
}


Infection::~Infection() {}

const sf::FloatRect Infection::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Infection::update(Mapa* map)
{
	bool a = Enemy::initTab[1][1] == 2;

	float x = this->speedX;
	float y = this->speedY;

	this->sprite.move(this->speedX, this->speedY);

	if (map->getCollision(this->sprite)) {
		//this->sprite.move(-this->speedX, this->speedY);
		std::vector<int>posVector = map->getPositionOnTileMap(this->sprite);
		if (initTab[posVector[0]][posVector[1] + 1] == 0 && initTab[posVector[0] - 1][posVector[1]] == 0) {
			this->sprite.setPosition(sprite.getPosition().x - 0.5f, sprite.getPosition().y);
			this->speedX = 0.f;
			this->speedY = 0.5f;
			this->sprite.move(this->speedX, this->speedY);

		}
		if (initTab[posVector[0] + 1][posVector[1]] == 0 && initTab[posVector[0]][posVector[1] - 1] == 0) {
			this->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 0.5f);
			this->speedX = 0.5f;
			this->speedY = 0.f;
			this->sprite.move(this->speedX, this->speedY);

		}
		if (initTab[posVector[0]][posVector[1] - 1] == 0 && initTab[posVector[0] - 1][posVector[1]] == 0) {
			this->sprite.setPosition(sprite.getPosition().x - 0.5f, sprite.getPosition().y);
			this->speedX = 0.f;
			this->speedY = -0.5f;
			this->sprite.move(this->speedX, this->speedY);
		}
		if (initTab[posVector[0]][posVector[1] + 1] == 0 && initTab[posVector[0] + 1][posVector[1]] == 0) {
			this->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 0.5f);
			this->speedX = 0.5f;
			this->speedY = 0.f;
			this->sprite.move(this->speedX, this->speedY);
		}
	}
}



void Infection::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
