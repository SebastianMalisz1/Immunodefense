#include "Map.h"


void Mapa::initTileMap()
{
    /*sf::Color(160, 160, 160) szary*/
    const int gridSize = 100;
    const int height = sf::VideoMode::getDesktopMode().height / gridSize;
    const int width = sf::VideoMode::getDesktopMode().width / gridSize;
    const int initTab[19][10] = {
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 2, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
      {1, 1, 1, 1, 0, 2, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
      {1, 1, 1, 2, 0, 2, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 2, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 2, 1, 1},
      {1, 2, 2, 1, 1, 1, 0, 0, 1, 1},
      {1, 2, 2, 1, 1, 1, 2, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
    };

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (initTab[i][j] == 1) {
                //background tiles
                sf::RectangleShape rectangle(sf::Vector2f(gridSize, gridSize));
                rectangle.setPosition(i * gridSize, j * gridSize);
                rectangle.setFillColor(sf::Color(0, 153, 76));
                //rectangle.setOutlineThickness(1.0f);
                rectangle.setOutlineColor(sf::Color::Black);
                grids.push_back(rectangle);
            }
            if (initTab[i][j] == 0) {
                //path
                sf::RectangleShape rectangle(sf::Vector2f(gridSize, gridSize));
                rectangle.setPosition(i * gridSize, j * gridSize);
                rectangle.setFillColor(sf::Color(255, 204, 153));
                //rectangle.setOutlineThickness(1.0f);
                rectangle.setOutlineColor(sf::Color::Black);
                path.push_back(rectangle);
            }
            if (initTab[i][j] == 2) {
                //towres
                sf::RectangleShape rectangle(sf::Vector2f(gridSize, gridSize));
                rectangle.setPosition(i * gridSize, j * gridSize);
                rectangle.setFillColor(sf::Color(160, 160, 160));
                //rectangle.setOutlineThickness(1.0f);
                rectangle.setOutlineColor(sf::Color::Black);
                placeForTower.push_back(rectangle);
            }
        }
    }
}



bool Mapa::getCollision(sf::Sprite sprite)
{
    bool returner = false;
    sf::FloatRect boundsEnemy = sprite.getGlobalBounds();
    
    for (int i = 0; i<grids.size(); i++) {
        sf::FloatRect boundsTile = grids[i].getGlobalBounds();
        if (boundsEnemy.intersects(boundsTile))
        {
            returner = true;
        }
    }
    for (int i = 0; i < placeForTower.size(); i++) {
        sf::FloatRect boundsTile = placeForTower[i].getGlobalBounds();
        if (boundsEnemy.intersects(boundsTile))
        {
            returner = true;
        }
    }
    return returner;
}

std::vector<int> Mapa::getPositionOnTileMap(sf::Sprite sprite)
{
    std::vector<int> returner = {0,0};
    
    sf::Vector2f position = sprite.getPosition();
    float x = position.x;
    float y = position.y;
 /*   float x = sf::VideoMode::getDesktopMode().height;
    float y = sf::VideoMode::getDesktopMode().width;*/
   
    for (int i = 0; i < sf::VideoMode::getDesktopMode().width; i = i + gridSize) {
        if (i < x && x < i + gridSize) {
            break;
        }
        else {
            returner[0]++;
        }
    }
    for (int i = 0; i < sf::VideoMode::getDesktopMode().height; i = i + gridSize) {
        if (i < y && y < i + gridSize) {
            break;
        }
        else {
            returner[1]++;
        }
    }

    return returner;
}


Mapa::Mapa(sf::RenderWindow& window)
{
	this->initTileMap();
    //this->initPath();
    //this->initPlaceForTower();
}

Mapa::~Mapa()
{

}


void Mapa::update()
{

}

void Mapa::render(sf::RenderTarget& target)
{
    for (const auto& rectangle : grids) {
        target.draw(rectangle);
    }

    for (const auto& rectangle : path) {
        target.draw(rectangle);
    }

    for (const auto& rectangle : placeForTower) {
        target.draw(rectangle);
    }
}
