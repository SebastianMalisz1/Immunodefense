#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Tower
{

public:


	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;



	Tower();
	Tower(sf::Vector2f positionOnMap);
	~Tower();
	void render(sf::RenderTarget* target);

};

