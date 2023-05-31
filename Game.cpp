#include "Game.h"

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

	//for (auto* bulletVaccine : this->bulletVaccine)
	//{
	//	bulletVaccine->render(this->window);
	//}
}

bool j = 0;
void Game::run()
{
	//po klikniciu myszka utw�rz w miejscu klikneicia sprite w kt�rym b�dzie opcja wyboru wierzy (grafika gdzie sa namalowanie wierze i odpowiadajace im przyciski)
	bool openToggleTurret = false;
	for (int i = 0; i < this->map->placeForTower.size(); i++)
		this->avaliableSpotsForTowers.push_back(this->map->placeForTower[i]);
	sf::Vector2f bounds;
	sf::Event ev;

	sf::RectangleShape toggleMenu(sf::Vector2f(600, 200));

	toggleMenu.setPosition(sf::VideoMode::getDesktopMode().width / 2.0f, sf::VideoMode::getDesktopMode().height / 2.0f);
	toggleMenu.setFillColor(sf::Color::White);
	toggleMenu.setOrigin(toggleMenu.getLocalBounds().width / 2.0f, toggleMenu.getLocalBounds().height / 2.0f);
	toggleMenu.setOutlineThickness(1.f);
	toggleMenu.setOutlineColor(sf::Color::Black);

	sf::RectangleShape togr(sf::Vector2f(100, 100));
	togr.setFillColor(sf::Color::White);
	togr.setOutlineThickness(1.f);
	togr.setOutlineColor(sf::Color::Black);



	while (this->window->isOpen())
	{



		while (this->window->pollEvent(ev))
		{
			if (ev.Event::type == sf::Event::Closed)
				this->window->close();
			if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape)
				this->window->close();
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
			if(j==1){
			if (ev.Event::KeyReleased && ev.Event::key.code == sf::Keyboard::Num1) {
				std::cout << "kliknieto wieze\n";
				this->towers.push_back(new Vaccine(bounds));
				openToggleTurret = false;
				j = 0;
			}
			else if (ev.Event::KeyReleased && ev.Event::key.code == sf::Keyboard::Num2) {
				std::cout << "kliknieto wieze\n";
				this->towers.push_back(new Pellet(bounds));
				openToggleTurret = false;
				j = 0;
			}
			else if (ev.Event::KeyReleased && ev.Event::key.code == sf::Keyboard::Num3) {
				std::cout << "kliknieto wieze\n";
				this->towers.push_back(new Syringe(bounds));
				openToggleTurret = false;
				j = 0;
			}
		}

		}

		std::cout << towers.size() << std::endl;
		for (int i=0; i < towers.size();i++)
		{
			if (this->towers[i]->attackSpeed > 50.f)
			{
				this->towers[i]->attackSpeed = 0.f;
			}
			else{
				this->towers[i]->attackSpeed += 1.f;
			}
		}
		//Vaccine shoot
		for (int i = 0; i < this->towers.size(); i++) {
			if (this->towers[i]->attackSpeed == 50.f && this->towers[i]->attackRange == 250.f) {
				sf::Vector2f towerPosition = this->towers[i]->position;
				float minimumDistance = std::numeric_limits<float>::max();
				Enemy* closestEnemy = nullptr;
				for (Enemy* enemy: enemies) {
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
				this->bullets.push_back(new Bullet(this->towers[i]->position, angle)); // zamiast new Bullet pisze new Syringe/Pellet/Vaccine
			}
			if (this->towers[i]->attackSpeed == 50.f && this->towers[i]->attackRange == 170.f) {
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
				this->bullets.push_back(new Bullet(this->towers[i]->position, angle));
			}
			if (this->towers[i]->attackSpeed == 50.f && this->towers[i]->attackRange == 120.f) {
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
				this->bullets.push_back(new Bullet(this->towers[i]->position, angle));
			}
		}

		//for (int i = 0; i < this->vaccineBullet.size(); i++) {
		//	for (int j = 0; j < this->enemies.size(); j++) {
		//		this->vaccineBullet[i]->sprite.move(this->enemies[j]->getPos());
		//		if (this->vaccineBullet[i]->sprite.getPosition() == this->enemies[j]->getPos()) {
		//			delete this->vaccineBullet[i];
		//			this->vaccineBullet.erase(this->vaccineBullet.begin() + i);
		//			i--; // Decrement i to account for the erased element
		//		}
		//	}
		//}

		//bulletb = new bullet //stwórz nowy obiekt bullet
		//			// calculate angle to find the direction of the ufo rocket
		//	double dx = p->x - i->x; // p - pozycja przeciwnikia, i - pozycja wierzy 
		//double dy = p->y - i->y;
		//double shooting_angle = std::atan2(dy, dx) 180.0 / 3.14;

		////ustawienie kierunku poruszania sie zgodnie z obliczonym shooting angle




		this->updateEnemies();

		//
		//update entities
		//

		this->window->clear();
		this->map->render(*this->window);

		//this->window->draw(toggleMenu);



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
			this->window->draw(toggleMenu);

		}
		//for (auto* bulletVaccine : this->bulletVaccine)
		//{
		//	bulletVaccine->render(this->window);
		//}
		this->window->display();
	}
}

void Game::updateEnemies()
{
	//float startPathX;
	//float startPathY;
	//Spawning
	this->spawnTimer += 0.1f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		/*	startPathX = map->path[0].getPosition().x;
			startPathY = map->path[0].getPosition().y;*/

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
	//unsigned counterInfection = 0;
	//for (auto* infection : this->infection)
	//{

	//	infection->update(this->map);

	//	if (infection->getBounds().left + 70.f > this->window->getSize().x)
	//	{
	//		delete this->infection.at(counterInfection);
	//		this->infection.erase(this->infection.begin() + counterInfection);
	//	}
	//	++counterInfection;
	//}
	//unsigned counterVirus = 0;
	//for (auto* virus : this->virus)
	//{

	//	virus->update(this->map);

	//	if (virus->getBounds().left + 70.f > this->window->getSize().x)
	//	{
	//		delete this->virus.at(counterVirus);
	//		this->virus.erase(this->virus.begin() + counterVirus);
	//	}
	//	++counterVirus;
	//}
}

