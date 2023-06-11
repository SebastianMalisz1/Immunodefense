#include "Game.h"

void Game::initStartWindow()
{
	sf::FloatRect playTextBounds = playText.getLocalBounds();
	sf::FloatRect leaderboardTextBounds = leaderboardText.getLocalBounds();
	sf::FloatRect exitTextBounds = exitText.getLocalBounds();
	//Load font
	if (!this->font.loadFromFile("Font/Lato-BlackItalic.ttf"))
	{
		std::cout << "ERROR::GAME::FAILED TO LOAD FONT" << "\n";
	}

	this->start.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height));
	this->start.setFillColor(sf::Color(0, 153, 76));

	this->play.setSize(sf::Vector2f(300.f, 100.f));
	this->play.setPosition(800.f, 500.f);
	this->play.setFillColor(sf::Color::White);
	this->play.setOutlineThickness(4.f);
	this->play.setOutlineColor(sf::Color::Black);

	this->leaderboard.setSize(sf::Vector2f(300.f, 100.f));
	this->leaderboard.setPosition(800.f, 650.f);
	this->leaderboard.setFillColor(sf::Color::White);
	this->leaderboard.setOutlineThickness(4.f);
	this->leaderboard.setOutlineColor(sf::Color::Black);

	this->exit.setSize(sf::Vector2f(300.f, 100.f));
	this->exit.setPosition(800.f, 800.f);
	this->exit.setFillColor(sf::Color::White);
	this->exit.setOutlineThickness(4.f);
	this->exit.setOutlineColor(sf::Color::Black);

	////Init point text
	this->startText.setPosition(sf::Vector2f(125.f, 50.f));
	this->startText.setFont(this->font);
	this->startText.setCharacterSize(200);
	this->startText.setString("IMMUNODEFENCE");
	this->startText.setFillColor(sf::Color::Black);

	this->playText.setPosition(this->play.getPosition().x + 55.f, this->play.getPosition().y);
	this->playText.setFont(this->font);
	this->playText.setCharacterSize(80);
	this->playText.setString("PLAY");
	this->playText.setFillColor(sf::Color::Black);

	this->leaderboardText.setPosition(this->leaderboard.getPosition().x + 15.f, this->leaderboard.getPosition().y + 23.f);
	this->leaderboardText.setFont(this->font);
	this->leaderboardText.setCharacterSize(40);
	this->leaderboardText.setString("LEADERBOARD");
	this->leaderboardText.setFillColor(sf::Color::Black);

	this->exitText.setPosition(this->exit.getPosition().x + 70.f, this->exit.getPosition().y);
	this->exitText.setFont(this->font);
	this->exitText.setCharacterSize(80);
	this->exitText.setString("EXIT");
	this->exitText.setFillColor(sf::Color::Black);
}

void Game::initText()
{
	if (!this->font.loadFromFile("Font/Lato-BlackItalic.ttf"))
	{
		std::cout << "ERROR::GAME::FAILED TO LOAD FONT" << "\n";
	}


	this->health.setPosition(20.f, 20.f);
	this->health.setFont(this->font);
	this->health.setCharacterSize(24);
	this->health.setFillColor(sf::Color::Black);
	

	this->goldText.setPosition(100.f, 20.f);
	this->goldText.setFont(this->font);
	this->goldText.setCharacterSize(24);
	this->goldText.setFillColor(sf::Color::White);
}


void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Immunodefence", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initMap()
{
	this->map = new Mapa(*this->window);
}

void Game::initBacteria()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

Game::Game()
{
	this->initStartWindow();
	this->initText();
	this->initWindow();
	this->initMap();
	this->initBacteria();
}

Game::~Game()
{
	delete this->window;

	//Delete Enemies
	for (auto* i : this->enemies)
	{
		delete i;
	}
	for (auto* i : this->towers)
	{
		delete i;
	}
}

bool j = 0;
void Game::run()
{
	//po klikniciu myszka utw�rz w miejscu klikneicia sprite w kt�rym b�dzie opcja wyboru wierzy (grafika gdzie sa namalowanie wierze i odpowiadajace im przyciski)
	bool openToggleTurret = false;
	bool startGame = false;
	for (int i = 0; i < this->map->placeForTower.size(); i++)
		this->avaliableSpotsForTowers.push_back(this->map->placeForTower[i]);
	sf::Vector2f bounds;
	sf::Event ev;

	initStartWindow();
	initText();

	if (!this->toggleTurretTexture.loadFromFile("Textures/toggleMenu.png"))
	{
		std::cout << "ERROR::GAME::INITTEXTURE::COULD NOR LOAD TEXTURE FILE" << "\n";
	}
	this->toggleTurret.setTexture(this->toggleTurretTexture);
	this->toggleTurret.setOrigin(sf::Vector2f(this->toggleTurret.getLocalBounds().width / 2.0f, this->toggleTurret.getLocalBounds().height / 2.0f));
	this->toggleTurret.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2.0f, sf::VideoMode::getDesktopMode().height / 2.0f));



	while (this->window->isOpen())
	{



		while (this->window->pollEvent(ev))
		{
			if (ev.Event::type == sf::Event::Closed)
				this->window->close();
			if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape)
				this->window->close();
			if (ev.Event::MouseButtonPressed && ev.Event::key.code == sf::Mouse::Left) {
				sf::FloatRect playButton = this->play.getGlobalBounds();
				sf::FloatRect leaderboardButton = this->leaderboard.getGlobalBounds();
				sf::FloatRect exitButton = this->exit.getGlobalBounds();
				if (playButton.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
					startGame = true;
				}
				if (leaderboardButton.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {

				}
				if (exitButton.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
					this->window->close();
				}
			}
			if (ev.Event::MouseButtonPressed && ev.Event::key.code == sf::Mouse::Left) {
				
				//finding avaliable spots for and palcing the tower there
				for (int i = 0; i < this->avaliableSpotsForTowers.size(); i++)
				{
					sf::FloatRect boundsPlaceForTowers = this->avaliableSpotsForTowers[i].getGlobalBounds();
					if (boundsPlaceForTowers.contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
					{
						bounds = this->avaliableSpotsForTowers[i].getPosition();
						this->avaliableSpotsForTowers.erase(this->avaliableSpotsForTowers.begin() + i);
						openToggleTurret = true;
						j = 1;
					}
				}
			}
				
				if (j == 1) {
					if (ev.Event::KeyReleased && ev.Event::key.code == sf::Keyboard::Num1) {
						this->towers.push_back(new Syringe(bounds));
						openToggleTurret = false;
						j = 0;
					}
					else if (ev.Event::KeyReleased && ev.Event::key.code == sf::Keyboard::Num2) {
						this->towers.push_back(new Pellet(bounds));
						openToggleTurret = false;
						j = 0;
					}
					else if (ev.Event::KeyReleased && ev.Event::key.code == sf::Keyboard::Num3) {
						this->towers.push_back(new Vaccine(bounds));
						openToggleTurret = false;
						j = 0;
					}
				}

			}

			std::cout << towers.size() << std::endl;
			for (int i = 0; i < towers.size(); i++)
			{
				if (this->towers[i]->attackSpeed > 50.f)
				{
					this->towers[i]->attackSpeed = 0.f;
				}
				else {
					this->towers[i]->attackSpeed += 1.f;
				}
			}
			//Vaccine shoot
			for (int i = 0; i < this->towers.size(); i++) {
				if (this->towers[i]->attackSpeed == 2.f && this->towers[i]->attackRange == 170.f) {
					sf::Vector2f towerPosition = this->towers[i]->position;
					float minimumDistance = std::numeric_limits<float>::max();
					Enemy* closestEnemy = nullptr;
					for (Enemy* enemy : enemies) {
						float distanceFromTower = std::sqrt(std::pow(enemy->getPos().x - towers[i]->position.x, 2) + std::pow(enemy->getPos().y - towers[i]->position.y, 2));
						if (distanceFromTower < minimumDistance)
						{
							minimumDistance = distanceFromTower;
							closestEnemy = enemy;
						}
					}
					double dx = closestEnemy->getPos().x - towers[i]->position.x;
					double dy = closestEnemy->getPos().y - towers[i]->position.y;
					double angle = std::atan2(dy, dx) * 180 / 3.14;
					if (minimumDistance < this->towers[i]->attackRange) {
						this->bullets.push_back(new VaccineBullet(this->towers[i]->position, angle));
					}
					for (int i = 0; i < bullets.size(); i++) {
						for (int j = 0; j < enemies.size(); j++) {
							sf::FloatRect bulletBounds = this->bullets[i]->sprite.getGlobalBounds();;
							sf::FloatRect enemyBounds = this->enemies[j]->getBounds();
							if (bulletBounds.intersects(enemyBounds)) {
								delete this->bullets[i];
								this->bullets.erase(this->bullets.begin() + i);
								i--;
								delete this->enemies[j];
								this->enemies.erase(this->enemies.begin() + j);
								j--;  // Decrement the index since the vector has been modified
								break;  // Exit the inner loop since the bullet has been deleted
							}
						}
					}

				}
				if (this->towers[i]->attackSpeed == 4.f && this->towers[i]->attackRange == 250.f) {
					sf::Vector2f towerPosition = this->towers[i]->position;
					float minimumDistance = std::numeric_limits<float>::max();
					Enemy* closestEnemy = nullptr;
					for (Enemy* enemy : enemies) {
						float distanceFromTower = std::sqrt(std::pow(enemy->getPos().x - towers[i]->position.x, 2) + std::pow(enemy->getPos().y - towers[i]->position.y, 2));
						if (distanceFromTower < minimumDistance)
						{
							minimumDistance = distanceFromTower;
							closestEnemy = enemy;
						}
					}
					double dx = closestEnemy->getPos().x - towers[i]->position.x;
					double dy = closestEnemy->getPos().y - towers[i]->position.y;
					double angle = std::atan2(dy, dx) * 180 / 3.14;
					if (minimumDistance < this->towers[i]->attackRange) {
						this->bullets.push_back(new SyringeBullet(this->towers[i]->position, angle));
					}
					for (int i = 0; i < bullets.size(); i++) {
						for (int j = 0; j < enemies.size(); j++) {
							sf::FloatRect bulletBounds = this->bullets[i]->sprite.getGlobalBounds();;
							sf::FloatRect enemyBounds = this->enemies[j]->getBounds();
							if (bulletBounds.intersects(enemyBounds)) {
								delete this->bullets[i];
								this->bullets.erase(this->bullets.begin() + i);
								i--;
								delete this->enemies[j];
								this->enemies.erase(this->enemies.begin() + j);
								j--;  // Decrement the index since the vector has been modified
								break;  // Exit the inner loop since the bullet has been deleted
							}
						}
					}
				}
				if (this->towers[i]->attackSpeed == 1.f && this->towers[i]->attackRange == 120.f) {
					sf::Vector2f towerPosition = this->towers[i]->position;
					float minimumDistance = std::numeric_limits<float>::max();
					Enemy* closestEnemy = nullptr;
					for (Enemy* enemy : enemies) {
						float distanceFromTower = std::sqrt(std::pow(enemy->getPos().x - towers[i]->position.x, 2) + std::pow(enemy->getPos().y - towers[i]->position.y, 2));
						if (distanceFromTower < minimumDistance)
						{
							minimumDistance = distanceFromTower;
							closestEnemy = enemy;
						}
					}
					double dx = closestEnemy->getPos().x - towers[i]->position.x;
					double dy = closestEnemy->getPos().y - towers[i]->position.y;
					double angle = std::atan2(dy, dx) * 180 / 3.14;
					if (minimumDistance < this->towers[i]->attackRange) {
						this->bullets.push_back(new PelletBullet(this->towers[i]->position, angle));
					}
					for (int i = 0; i < bullets.size(); i++) {
						for (int j = 0; j < enemies.size(); j++) {
							sf::FloatRect bulletBounds = this->bullets[i]->sprite.getGlobalBounds();;
							sf::FloatRect enemyBounds = this->enemies[j]->getBounds();
							if (bulletBounds.intersects(enemyBounds)) {
								delete this->bullets[i];
								this->bullets.erase(this->bullets.begin() + i);
								i--;
								//this->enemies[j]->
								delete this->enemies[j];
								this->enemies.erase(this->enemies.begin() + j);
								j--;  // Decrement the index since the vector has been modified
								break;  // Exit the inner loop since the bullet has been deleted
							}
						}
					}
				}
			}
			//
			//update entities
			//
			

			this->window->clear();

			std::stringstream ss;
			ss << "Health: " << this->hp;
			this->health.setString(ss.str());


			std::stringstream ss1;
			ss1 << "Gold: " << this->gold;
			this->goldText.setString(ss1.str());

			if (!startGame) {
				this->window->draw(this->start);
				this->window->draw(this->startText);
				this->window->draw(this->play);
				this->window->draw(this->playText);
				this->window->draw(this->leaderboard);
				this->window->draw(this->leaderboardText);
				this->window->draw(this->exit);
				this->window->draw(this->exitText);
			}
			else {
				this->window->draw(this->health);
				this->window->draw(this->goldText);
				this->updateEnemies();
				this->map->render(*this->window);

				//Draw all the stuff
				for (auto* enemies : this->enemies)
				{
					enemies->render(this->window);
				}

				for (auto* tower : this->towers)
				{
					tower->render(this->window);
				}
				for (auto* bullet : this->bullets)
				{
					bullet->update(this->window);
					bullet->render(this->window);
				}
				for (auto i = bullets.begin(); i != bullets.end();)
				{
					if ((*i)->life == 0) {
						delete (*i);
						i = bullets.erase(i);
					}
					else i++;
				}

				if (openToggleTurret) {
					this->window->draw(this->toggleTurret);

				}
			}
			this->window->display();
	}
}

void Game::updateEnemies()
{
	//Spawning
	this->spawnTimer += 0.1f;
	if (this->spawnTimer >= this->spawnTimerMax) {
		this->enemies.push_back(new Bacteria(-10.f, 750.f));
		this->enemies.push_back(new Infection(-10.f, 750.f));
		this->enemies.push_back(new Virus(-10.f, 750.f));
		this->spawnTimer = 0.f;
	}

	//Update
	unsigned counterBacteria = 0;
	for (auto* enemies : this->enemies)
	{
		enemies->update(this->map);

		if (enemies->getBounds().left + 70.f > this->window->getSize().x)
		{
			delete this->enemies.at(counterBacteria);
			this->enemies.erase(this->enemies.begin() + counterBacteria);
		}
		++counterBacteria;
	}
}


