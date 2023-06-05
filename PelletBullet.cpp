#include "PelletBullet.h"
#include <iostream>


PelletBullet::PelletBullet() {
	if (!this->texture.loadFromFile("Textures/czerwonaBak.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	this->sprite.setTexture(this->texture);
	this->sprite.scale(2.f, 2.f);

}

PelletBullet::PelletBullet(sf::Vector2f positionOnMap, float angle1) {

	if (!this->texture.loadFromFile("Textures/czerwonaBak.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}

	this->sprite.setTexture(this->texture);
	this->sprite.scale(2.f, 2.f);

	this->sprite.setPosition(positionOnMap);
	this->position = positionOnMap;
	this->angle = angle1;
}

PelletBullet::~PelletBullet() {

}

void PelletBullet::update(sf::RenderTarget* target)
{
	if (this->position.x > target->getSize().x || this->position.x < 0) {
		this->life = 0;
	}
	if (this->position.y > target->getSize().y || this->position.y < 0) {
		this->life = 0;
	}
	this->position.x += cos(this->angle * 0.017453f) * 5;

	this->position.y += sin(this->angle * 0.017453f) * 5;
	//std::cout << "POS: " << this->position.x << ", " << this->position.y << std::endl;
	this->sprite.setPosition(position);
}

void PelletBullet::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
}

