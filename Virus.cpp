#include "Virus.h"

#include <iostream>

void Virus::initVariables()
{
	this->speedX = 0.7f;
	this->speedY = 0.f;
	this->hpMax = 4;
	this->hp = this->hpMax;
	this->damage = 1;
	this->gold = 15;
}

void Virus::initTexture()
{
	//srand(time(NULL));
	//int liczbaLosowa = rand() % 3;
	//std::cout << liczbaLosowa << std::endl;
	//
	if (/*liczbaLosowa == 0 && */!this->texture.loadFromFile("Textures/zoltaBak.png"))
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

void Virus::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(sf::Vector2f(20.f, 20.f));
	this->sprite.setOrigin(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f);
	this->sprite.scale(0.9f, 0.9f);
	//this->sprite.setColor(sf::Color::Black);
}



Virus::Virus(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->sprite.setPosition(pos_x, pos_y);
}


Virus::~Virus() {}

const sf::FloatRect Virus::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Virus::update(Mapa* map)
{
	bool a = Enemy::initTab[1][1] == 2;

	float x = this->speedX;
	float y = this->speedY;

	this->sprite.move(this->speedX, this->speedY);

	if (map->getCollision(this->sprite)) {
		//this->sprite.move(-this->speedX, this->speedY);
		std::vector<int>posVector = map->getPositionOnTileMap(this->sprite);
		if (initTab[posVector[0]][posVector[1] + 1] == 0 && initTab[posVector[0] - 1][posVector[1]] == 0) {
			this->sprite.setPosition(sprite.getPosition().x - 0.8f, sprite.getPosition().y);
			this->speedX = 0.f;
			this->speedY = 0.8f;
			this->sprite.move(this->speedX, this->speedY);

		}
		if (initTab[posVector[0] + 1][posVector[1]] == 0 && initTab[posVector[0]][posVector[1] - 1] == 0) {
			this->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 0.8f);
			this->speedX = 0.8f;
			this->speedY = 0.f;
			this->sprite.move(this->speedX, this->speedY);

		}
		if (initTab[posVector[0]][posVector[1] - 1] == 0 && initTab[posVector[0] - 1][posVector[1]] == 0) {
			this->sprite.setPosition(sprite.getPosition().x - 0.8f, sprite.getPosition().y);
			this->speedX = 0.f;
			this->speedY = -0.8f;
			this->sprite.move(this->speedX, this->speedY);
		}
		if (initTab[posVector[0]][posVector[1] + 1] == 0 && initTab[posVector[0] + 1][posVector[1]] == 0) {
			this->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 0.8f);
			this->speedX = 0.8f;
			this->speedY = 0.f;
			this->sprite.move(this->speedX, this->speedY);
		}
	}
}



void Virus::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

