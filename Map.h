#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Enemy.h"
#include "Bacteria.h"

class Map
{
private:
	sf::VertexArray tileMap;

	void initTileMap();

public:
	Map(sf::RenderWindow& window);
	~Map();

	void placeBacteria(Bacteria& bacteria, int x, int y);

	void update();
	void render(sf::RenderTarget& target);
};

