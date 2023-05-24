#pragma once
#include <iostream>
#include "Map.h"
#include "Enemy.h"
#include "Bacteria.h"
#include "Infection.h"
#include "Virus.h"
#include "Tower.h"
#include "Vaccine.h"
#include "Pellet.h"
#include "Syringe.h"


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

	std::vector<Vaccine*> vaccine;
	std::vector<Pellet*> pellet;
	std::vector<Syringe*> syringe;
	//std::vector<Vaccine*> vaccines;

	void initTexture();
	void initSprite();
	
	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Bacteria*> bacteria;
	std::vector<Infection*> infection;
	std::vector<Virus*> virus;

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

