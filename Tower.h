#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Tower
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

	void initVariables();

	Tower();
	Tower(sf::Vector2f positionOnMap);
	~Tower();
	void render(sf::RenderTarget* target);

};

