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

}


void Game::run()
{
	//po klikniciu myszka utwórz w miejscu klikneicia sprite w którym bêdzie opcja wyboru wierzy (grafika gdzie sa namalowanie wierze i odpowiadajace im przyciski)
	bool openToggleTurret = false;
	for (int i = 0; i < this->map->placeForTower.size(); i++)
		this->avaliableSpotsForTowers.push_back(this->map->placeForTower[i]);
	sf::Vector2f bounds;
	sf::Event ev;
	
	sf::RectangleShape toggleMenu(sf::Vector2f(200, 100));
	
	toggleMenu.setPosition(sf::Vector2f(300, 200));
	toggleMenu.setFillColor(sf::Color::White);
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
			/*if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Num1) {
				this->towersOnScreen.push_back(new Tower(bounds));
				openToggleTurret = false;
			}*/

				
		
		}
		
		




		


		this->updateBacteria();

		//
		//update entities
		//

		
		
		
	

		this->window->clear();
		
		this->map->render(*this->window);

		//this->window->draw(toggleMenu);

		if (openToggleTurret) {
			this->window->draw(toggleMenu);

		}
		

		//Draw all the stuff
		for (auto* bacteria : this->bacteria)
		{
			bacteria->render(this->window);
		}

		for (auto* towers : this->towersOnScreen)
		{
			towers->render(this->window);
		}

		
		this->window->display();
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

//void Game::update()
//{
//	this->updateBacteria();
//}

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