#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Tower.h"

class Syringe : public Tower
{
private:
	int cost;
	float attackSpeed;
	int damage;
	float attackRange;

	sf::Sprite sprite;
	sf::Texture texture;
public:

	sf::Vector2f position;




	Syringe();
	Syringe(sf::Vector2f positionOnMap);
	~Syringe();
	void render(sf::RenderTarget* target);

};

