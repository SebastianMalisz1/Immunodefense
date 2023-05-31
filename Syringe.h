#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Tower.h"

class Syringe : public Tower
{
public:

	void initVariables();

	sf::CircleShape radius;



	Syringe();
	Syringe(sf::Vector2f positionOnMap);
	~Syringe();
	virtual void render(sf::RenderTarget* target) override;

};

