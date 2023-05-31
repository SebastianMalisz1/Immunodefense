#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Tower.h"

class Bullet
{
public:

	sf::Sprite sprite;
	sf::Texture texture;
	float angle;
	int speed;
	sf::Vector2f position;
	int life = 1;

	Bullet();
	Bullet(sf::Vector2f position, float angle1);
	~Bullet();
	void update(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

