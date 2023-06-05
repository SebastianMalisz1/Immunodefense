#include "BulletVaccine.h"

#include <iostream>


BulletVaccine::BulletVaccine() {
	if (!this->texture.loadFromFile("Textures/vaccine.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.8f, 0.8f);

}

BulletVaccine::BulletVaccine(sf::Vector2f positionOnMap, float angle1) {

	if (!this->texture.loadFromFile("Textures/vaccine.png"))
	{
		std::cout << "ERROR::VACCINE::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}

	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.8f, 0.8f);

	this->sprite.setPosition(positionOnMap);
	this->position = positionOnMap;
	this->angle = angle1;
}

BulletVaccine::~BulletVaccine() {

}

void BulletVaccine::update(sf::RenderTarget* target)
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
void BulletVaccine::render(sf::RenderTarget* target) {
	target->draw(this->sprite);
}

