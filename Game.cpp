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

	//Delete bacterias
	for (auto* i : this->enemies)
	{
		delete i;
	}
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvents();
		this->update();
		this->render();
		this->updatePollEvents();
	}
}

void Game::updatePollEvents()
{
	//seba jesli czytasz to po miesiacu to zrob tak
	//po klikniciu myszka hehe utwórz w miejscu klikneicia sprite w którym bêdzie opcja wyboru wierzy (grafika gdzie sa namalowanie wierze i odpowiadajace im przyciski)
	/*bool openToggleTurret = false;*/
	sf::Event ev;
	while (this->window->pollEvent(ev))
	{
		if (ev.Event::type == sf::Event::Closed)
			this->window->close();
		if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
		if (ev.Event::MouseButtonPressed && ev.Event::key.code == sf::Mouse::Left) {
			bool openToggleTurret = true;
		}

		/*if (openToggleTurret) {
			sf::Vector2i mousePosition = sf::Mouse::getPosition();
			sf::RectangleShape toggleMenu(sf::Vector2f(200, 200));
			toggleMenu.setPosition(mousePosition.x, mousePosition.y);
			toggleMenu.setFillColor(sf::Color(69, 69, 69));
			toggleMenu.setOutlineColor(sf::Color::Black);
			window->draw(toggleMenu);

		}*/
	
			
		
	}
}

void Game::updateBacteria()
{
	//Spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->bacteria.push_back(new Bacteria(-10.f, 750.f));
		this->spawnTimer = 0.f;
	}

	//Update
	unsigned counter = 0;
	for (auto* bacteria : this->bacteria)
	{
		
		bacteria->update(this->map);

		if (bacteria->getBounds().left + 50.f > this->window->getSize().x)
		{
			delete this->bacteria.at(counter);
			this->bacteria.erase(this->bacteria.begin() + counter);
		}
		++counter;
	}
}

void Game::updateVaccine()
{
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && )
	//{
	//	
	//}
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
