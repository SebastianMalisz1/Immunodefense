#include "Syringe.h"
#include <iostream>



void Syringe::initVariables()
{
	this->cost = 200;
	this->attackSpeed = 4.f;
	this->damage = 1;
	this->attackRange = 250.f;
}

Syringe::Syringe() {
	initVariables();
	if (!this->texture.loadFromFile("Textures/syringe.png"))
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

Syringe::Syringe(sf::Vector2f positionOnMap) :Tower(positionOnMap) {
	initVariables();

	if (!this->texture.loadFromFile("Textures/syringe.png"))
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
	this->radius.setPosition(sprite.getPosition().x - 75.f, sprite.getPosition().y - 75.f);

}

Syringe::~Syringe() {

}

void Syringe::upgrade()
{
	this->attackRange = 300.f;
	this->damage = 3;
	this->attackSpeed = 4.f;

	float radiusSize = this->attackRange;
	this->radius.setOrigin(radiusSize / 2.f, radiusSize / 2.f);
	this->radius.setRadius(radiusSize);
	this->radius.setOutlineThickness(1.f);
	this->radius.setOutlineColor(sf::Color::Black);
	this->radius.setFillColor(sf::Color::Transparent);
	this->radius.setPosition(sprite.getPosition().x - 100.f, sprite.getPosition().y - 100.f);
}

void Syringe::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
	target->draw(this->radius);
}

