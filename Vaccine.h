#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Tower.h"
#include "BulletVaccine.h"
#include "Enemy.h"

class Vaccine: public Tower
{
public:

	void initVariables();

	sf::CircleShape radius;



	Vaccine();
	Vaccine(sf::Vector2f positionOnMap);
	~Vaccine();
	virtual void render(sf::RenderTarget* target) override;

};

