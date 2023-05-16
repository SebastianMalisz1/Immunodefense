#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Enemy.h"
#include "Bacteria.h"



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

	
	


	Mapa(sf::RenderWindow& window);
	Mapa();
	~Mapa();

	void update();
	void render(sf::RenderTarget& target);
	bool getCollision(sf::Sprite sprite);
	std::vector<int> getPositionOnTileMap(sf::Sprite sprite);
};

