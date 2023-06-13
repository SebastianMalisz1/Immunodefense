#include "Tower.h"

#include <iostream>

void Tower::initVariables()
{
	this->cost = 0;
	this->attackSpeed = 0.f;
	this->damage = 0;
	this->attackRange = 0.f;
}

Tower::Tower(){
	if (!this->texture.loadFromFile("Textures/tower.png"))
	{
		std::cout << "ERROR::ENEMY::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	this->sprite.setTexture(this->texture);
	
}

Tower::Tower(sf::Vector2f positionOnMap){

	if (!this->texture.loadFromFile("Textures/tower.png"))
	{
		std::cout << "ERROR::ENEMY::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	
	this->sprite.setTexture(this->texture);

	this->sprite.setPosition(positionOnMap);
	position = positionOnMap;
}

Tower::~Tower() {

}
const sf::FloatRect Tower::getBounds() const
{
	return this->sprite.getGlobalBounds();
}
void Tower::upgrade()
{
	this->attackSpeed += 0.f;
	this->damage += 0;
	this->attackRange += 100.f;
}

void Tower::render(sf::RenderTarget* target){
	target->draw(this->sprite);
 }



