#pragma once
#include <iostream>
#include "Map.h"
#include "Enemy.h"
#include "Bacteria.h"
#include "Tower.h"
#include "Vaccine.h"

class Tower;

class Game
{
private:
	sf::RenderWindow* window;

	//Map
	Mapa* map;

	//Turret
	sf::Sprite toggleTurret;
	sf::Texture toggleTurretTexture;

	std::vector<sf::RectangleShape> avaliableSpotsForTowers;

	std::vector<Tower*> towersOnScreen;
	//std::vector<Vaccine*> vaccines;

	void initTexture();
	void initSprite();
	
	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;
	std::vector<Bacteria*> bacteria;

	void initWindow();
	void initMap();
	void initBacteria();

public:
	Game();
	virtual ~Game();

	void run();
	void updateBacteria();
	void updateVaccine();
	void render();
};

