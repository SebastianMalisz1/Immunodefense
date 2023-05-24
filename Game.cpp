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
	for (auto* i : this->bacteria)
	{
		delete i;
	}
	for (auto* i : this->infection)
	{
		delete i;
	}
	for (auto* i : this->virus)
	{
		delete i;
	}
	for (auto* towers : this->towersOnScreen)
	{
		towers->render(this->window);
	}
}


void Game::run()
{
	//po klikniciu myszka utwórz w miejscu klikneicia sprite w którym bêdzie opcja wyboru wierzy (grafika gdzie sa namalowanie wierze i odpowiadajace im przyciski)
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
					}
				}





			}

			if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Num1) {
				std::cout << "kliknieto wieze\n";
				this->towersOnScreen.push_back(new Tower(bounds));
				openToggleTurret = false;
			}
			if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Num2) {
				std::cout << "kliknieto wieze\n";
				this->towersOnScreen.push_back(new Vaccine(bounds));
				openToggleTurret = false;
			}
			if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Num3) {
				std::cout << "kliknieto wieze\n";
				this->towersOnScreen.push_back(new Vaccine(bounds));
				openToggleTurret = false;
			}
		
		}
		
		




		


		this->updateEnemies();

		//
		//update entities
		//

		
		
		
	

		this->window->clear();
		
		this->map->render(*this->window);

		//this->window->draw(toggleMenu);

		

		//Draw all the stuff
		for (auto* bacteria : this->bacteria)
		{
			bacteria->render(this->window);
		}

		for (auto* infection : this->infection)
		{
			infection->render(this->window);
		}
		
		for (auto* virus : this->virus)
		{
			virus->render(this->window);
		}

		for (auto* towers : this->towersOnScreen)
		{
			towers->render(this->window);
		}

		if (openToggleTurret) {
			this->window->draw(toggleMenu);

		}
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

		this->bacteria.push_back(new Bacteria(-10.f, 750.f));
		this->infection.push_back(new Infection(-10.f, 750.f));
		this->virus.push_back(new Virus(-10.f,750.f));
		this->spawnTimer = 0.f;
	}

	//Update
	unsigned counterBacteria = 0;
	for (auto* bacteria : this->bacteria)
	{

		bacteria->update(this->map);

		if (bacteria->getBounds().left + 70.f > this->window->getSize().x)
		{
			delete this->bacteria.at(counterBacteria);
			this->bacteria.erase(this->bacteria.begin() + counterBacteria);
		}
		++counterBacteria;
	}
	unsigned counterInfection = 0;
	for (auto* infection : this->infection)
	{

		infection->update(this->map);

		if (infection->getBounds().left + 70.f > this->window->getSize().x)
		{
			delete this->infection.at(counterInfection);
			this->infection.erase(this->infection.begin() + counterInfection);
		}
		++counterInfection;
	}
	unsigned counterVirus = 0;
	for (auto* virus : this->virus)
	{

		virus->update(this->map);

		if (virus->getBounds().left + 70.f > this->window->getSize().x)
		{
			delete this->virus.at(counterVirus);
			this->virus.erase(this->virus.begin() + counterVirus);
		}
		++counterVirus;
	}
}

void Game::updateVaccine()
{
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && )
	//{
	//	
	//}
}

//void Game::update()
//{
//	this->updateBacteria();
//}

//void Game::render()
//{
//	this->window->clear();
//	this->map->render(*this->window);
//
//	//Draw all the stuff
//	for (auto* bacteria : this->bacteria)
//	{
//		bacteria->render(this->window);
//	}
//
//	this->window->display();
//}