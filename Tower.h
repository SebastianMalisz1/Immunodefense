#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Tower
{
public:
	int cost;
	float attackSpeed;
	int damage;
	float attackRange;

	virtual void initVariables();

	sf::Sprite sprite;
	sf::Texture texture;

	sf::Vector2f position;


	Tower();
	Tower(sf::Vector2f positionOnMap);
	~Tower();
	virtual void upgrade();
	virtual void render(sf::RenderTarget* target);

};

