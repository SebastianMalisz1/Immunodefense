#include "Vaccine.h"
#include <iostream>



void Vaccine::initVariables()
{
	this->cost = 5;
	this->attackSpeed = 2.f;
	this->damage = 1;
	this->attackRange = 170.f;
}

Vaccine::Vaccine() {
	initVariables();
	if (!this->texture.loadFromFile("Textures/vaccine.png"))
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

Vaccine::Vaccine(sf::Vector2f positionOnMap):Tower(positionOnMap) {
	initVariables();

	if (!this->texture.loadFromFile("Textures/vaccine.png"))
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
	this->radius.setPosition(sprite.getPosition().x - 40.f, sprite.getPosition().y - 40.f);
}

Vaccine::~Vaccine() {

}

void Vaccine::upgrade() {
	this->attackRange += 30.f;
	this->damage += 1;
}

void Vaccine::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
	target->draw(this->radius);
}

