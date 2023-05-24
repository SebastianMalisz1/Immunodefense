#include "Syringe.h"
#include <iostream>



Syringe::Syringe() {
	if (!this->texture.loadFromFile("Textures/zielonyWir.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	this->sprite.setTexture(this->texture);


}

Syringe::Syringe(sf::Vector2f positionOnMap) :Tower(positionOnMap) {

	if (!this->texture.loadFromFile("Textures/zielonyWir.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}

	this->sprite.setTexture(this->texture);

	this->sprite.setPosition(positionOnMap);
}

Syringe::~Syringe() {

}

void Syringe::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
}

