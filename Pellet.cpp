#include "Pellet.h"
#include <iostream>



Pellet::Pellet() {
	if (!this->texture.loadFromFile("Textures/czerwonaBak.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	this->sprite.setTexture(this->texture);


}

Pellet::Pellet(sf::Vector2f positionOnMap) :Tower(positionOnMap) {

	if (!this->texture.loadFromFile("Textures/czerwonaBak.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}

	this->sprite.setTexture(this->texture);


	this->sprite.setPosition(positionOnMap);
}

Pellet::~Pellet() {

}

void Pellet::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
}

