#include "Vaccine.h"
#include <iostream>


void Vaccine::initVariables()
{
	this->cost = 20;
	this->attackSpeed = 2.0f;
	this->damage = 0;
	this->attackRange = 0;
}

Vaccine::Vaccine() {
	if (!this->texture.loadFromFile("Textures/vaccine.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.2f, 0.2f);

}

Vaccine::Vaccine(sf::Vector2f positionOnMap){

	if (!this->texture.loadFromFile("Textures/vaccine.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}

	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.2f, 0.2f);

	this->sprite.setPosition(positionOnMap);
}

Vaccine::~Vaccine() {

}

void Vaccine::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
}

