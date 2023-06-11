#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Tower.h"

class Pellet : public Tower
{
public:


	virtual void initVariables() override;


	sf::CircleShape radius;




	Pellet();
	Pellet(sf::Vector2f positionOnMap);
	~Pellet();
	virtual void upgrade() override;
	virtual void render(sf::RenderTarget* target) override;

};

