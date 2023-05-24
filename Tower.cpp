#include "Tower.h"

#include <iostream>

void Tower::initVariables()
{
	int cost = 0;
	float attackSpeed = 0;
	int damage = 0;
	float attackRange = 0;
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
}

Tower::~Tower() {

}
void Tower::render(sf::RenderTarget* target){
	target->draw(this->sprite);
 }



