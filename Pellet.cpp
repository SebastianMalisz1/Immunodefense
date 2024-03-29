#include "Pellet.h"
#include <iostream>



void Pellet::initVariables()
{
	this->cost = 100;
	this->attackSpeed = 1.f;
	this->damage = 3;
	this->attackRange = 120.f;
}

Pellet::Pellet() {
	initVariables();
	if (!this->texture.loadFromFile("Textures/pellet.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	this->sprite.setTexture(this->texture);
	float radiusSize = this->attackRange;

	this->radius.setOrigin(radiusSize / 2.f, radiusSize / 2.f);
	this->radius.setOutlineThickness(1.f);
	this->radius.setOutlineColor(sf::Color::Black);
	this->radius.setFillColor(sf::Color::Transparent);
	this->radius.setRadius(radiusSize);

}

Pellet::Pellet(sf::Vector2f positionOnMap) :Tower(positionOnMap) {
	initVariables();

	if (!this->texture.loadFromFile("Textures/pellet.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}

	this->sprite.setTexture(this->texture);


	float radiusSize = this->attackRange;

	this->radius.setOrigin(radiusSize / 2.f, radiusSize / 2.f);
	this->radius.setRadius(radiusSize);
	this->radius.setOutlineThickness(1.f);
	this->radius.setOutlineColor(sf::Color::Black);
	this->radius.setFillColor(sf::Color::Transparent);

	this->sprite.setPosition(positionOnMap);
	this->radius.setPosition(sprite.getPosition().x - 15.f, sprite.getPosition().y - 15.f);
}

Pellet::~Pellet() {

}

void Pellet::upgrade()
{
	this->attackRange = 200.f;
	this->damage = 5;
	this->attackSpeed = 1.f;

	float radiusSize = this->attackRange;
	this->radius.setOrigin(radiusSize / 2.f, radiusSize / 2.f);
	this->radius.setRadius(radiusSize);
	this->radius.setOutlineThickness(1.f);
	this->radius.setOutlineColor(sf::Color::Black);
	this->radius.setFillColor(sf::Color::Transparent);
	this->radius.setPosition(sprite.getPosition().x - 60.f, sprite.getPosition().y - 40.f);
}

void Pellet::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
	target->draw(this->radius);
}

