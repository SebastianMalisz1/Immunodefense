#pragma once
#include <iostream>
#include "Map.h"
#include "Enemy.h"
#include "Bacteria.h"

class Game
{
private:
	sf::RenderWindow* window;

	//Map
	Map* map;

	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Bacteria*> bacteria;

	void initWindow();
	void initMap();
	void initBacteria();

public:
	Game();
	virtual ~Game();

	void run();
	void updatePollEvents();
	void updateBacteria();
	void update();
	void render();
};

