#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include "Map.h"
#include "Enemy.h"
#include "Bacteria.h"
#include "Infection.h"
#include "Virus.h"
#include "Tower.h"
#include "Vaccine.h"
#include "Pellet.h"
#include "Syringe.h"
#include "Bullet.h"
#include "VaccineBullet.h"


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

	std::vector<Tower*> towers;

	std::vector<Bullet*> bullets;

	void initTexture();
	void initSprite();
	
	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	void initWindow();
	void initMap();
	void initBacteria();

public:
	Game();
	virtual ~Game();

	void run();
	void updateEnemies();
	void updateVaccine();
	//void render();
};

