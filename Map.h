#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Enemy.h"
#include "Bacteria.h"
#include <iostream>

const int initTab[19][10] = {
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 2, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
      {1, 1, 1, 1, 0, 2, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
      {1, 1, 1, 2, 0, 2, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 2, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 2, 1, 1},
      {1, 2, 2, 1, 1, 1, 0, 0, 1, 1},
      {1, 2, 2, 1, 1, 1, 2, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
};

class Mapa
{
public:

	const int gridSize = 100;
	const int height = sf::VideoMode::getDesktopMode().height / gridSize;
	const int width = sf::VideoMode::getDesktopMode().width / gridSize;

	//sf::VertexArray tileMap;
	//sf::RectangleShape grid;
	std::vector<sf::RectangleShape> grids;
	std::vector<sf::RectangleShape> path;
	std::vector<sf::RectangleShape> placeForTower;


	void initTileMap();

	//Turret
	sf::Sprite toggleTurret;
	sf::Texture toggleTurretTexture;

	//std::vector<Tower*> towers;
	//std::vector<Vaccine*> vaccines;

	void initTexture();
	void initSprite();
	


	Mapa(sf::RenderWindow& window);
	Mapa();
	~Mapa();

	void update();
	void render(sf::RenderTarget& target);
	bool getCollision(sf::Sprite sprite);
	std::vector<int> getPositionOnTileMap(sf::Sprite sprite);
};

