#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <array>
#include <chrono>
#include <memory>
#include <thread>
#include <regex>
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
#include "PelletBullet.h"
#include "SyringeBullet.h"




class Game
{
private:
	sf::RenderWindow* window;
	//Staring window
	sf::Font font;
	sf::Text startText;
	sf::Text playText;
	sf::Text leaderboardText;
	sf::Text exitText;
	sf::Text gameOverText;
	sf::RectangleShape start;
	sf::RectangleShape play;
	sf::RectangleShape leaderboardRectangle;
	sf::RectangleShape exit;
	sf::RectangleShape endGame;

	sf::Text goldText;
	sf::Text health;
	sf::Text pointsText;

	sf::RectangleShape upgrade;
	sf::Text upgradeText;

	sf::RectangleShape leaderboardScreenShow;
	sf::Text leaderboardTitle;
	sf::Text enterNicknameText;
	sf::Text nicknameText;
	sf::Text nicknameTextinLeanderboard;
	sf::Text hintNicknameText;
	sf::RectangleShape backButton;
	sf::RectangleShape inputbox;
	sf::Text backButtonText;


	sf::RectangleShape playAgain;
	sf::Text playAgainText;
	sf::RectangleShape exitGameOver;
	sf::Text exitGameOverText;


	//Map
	Mapa* map;

	//Turret
	sf::Sprite toggleTurret;
	sf::Texture toggleTurretTexture;

	std::vector<sf::RectangleShape> avaliableSpotsForTowers;
	std::vector<sf::RectangleShape> towersForUpgrade;

	std::vector<Tower*> towers;

	std::vector<Bullet*> bullets;

	int hp;
	int gold;
	int points;


	std::chrono::steady_clock::time_point startTime;
	
	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	void initStartWindow();
	void initLeaderboardWindow();
	void initGameOverWindow();
	void initText();
	void initToggleMenu();
	void initWindow();
	void initMap();
	void initBacteria();

public:
	Game();
	virtual ~Game();

	void startTimer();
	bool isDurationPassed(std::chrono::steady_clock::duration duration);


	void run();
	void updateEnemies();
	void updateVaccine();
	//void render();
};

