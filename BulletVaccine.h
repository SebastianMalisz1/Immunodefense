#pragma once
#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class BulletVaccine :
    public Bullet
{
public:
	BulletVaccine();
	BulletVaccine(sf::Vector2f position, float angle1);
	~BulletVaccine();
	virtual void update(sf::RenderTarget* target) override;
	virtual void render(sf::RenderTarget* target) override;
};

