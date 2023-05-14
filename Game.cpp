#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Immunodefence", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initMap()
{
	this->map = new Map(*this->window);
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

	//Delete enemies
	for (auto* i : this->bacteria)
	{
		delete i;
	}
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvents();
		this->render();
	}
}

void Game::updatePollEvents()
{
	sf::Event ev;
	while (this->window->pollEvent(ev))
	{
		if (ev.Event::type == sf::Event::Closed)
			this->window->close();
		if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::updateBacteria()
{
	//Spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->bacteria.push_back(new Bacteria(rand() % this->window->getSize().x - 20.f, -100.f));
		this->spawnTimer = 0.f;
	}
	
}

void Game::update()
{
	this->updateBacteria();
}

void Game::render()
{
	this->window->clear();
	this->map->render(*this->window);
	//Draw all the stuff
	for (auto* bacteria : this->bacteria)
	{
		bacteria->render(this->window);
	}

	this->window->display();
}
