#include "Vaccine.h"
#include <iostream>



Vaccine::Vaccine() {
	if (!this->texture.loadFromFile("Textures/vaccine.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.4f, 0.4f);

}

Vaccine::Vaccine(sf::Vector2f positionOnMap):Tower(positionOnMap) {

	if (!this->texture.loadFromFile("Textures/vaccine.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}

	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.4f, 0.4f);

	this->sprite.setPosition(positionOnMap);
}

Vaccine::~Vaccine() {

}

void Vaccine::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
}

