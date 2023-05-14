#include "Map.h"


void Map::initTileMap()
{
    const int tileSize = 50; // Set the size of each tile
    const int mapWidth = 16; // Set the width of the tilemap (in tiles)
    const int mapHeight = 12; // Set the height of the tilemap (in tiles)

    this->tileMap.setPrimitiveType(sf::Quads);
    this->tileMap.resize(mapWidth * mapHeight * 4); // Each tile requires 4 vertices

    // Create the tilemap
    for (int x = 0; x < mapWidth; ++x)
    {
        for (int y = 0; y < mapHeight; ++y)
        {
            //Get the current tile number

            // Get a pointer to the current tile's quad
            sf::Vertex* tile = &tileMap[(x + y * mapWidth) * 4];

            // Set the position of the vertices
            tile[0].position = sf::Vector2f(x * tileSize, y * tileSize);
            tile[1].position = sf::Vector2f((x + 1) * tileSize, y * tileSize);
            tile[2].position = sf::Vector2f((x + 1) * tileSize, (y + 1) * tileSize);
            tile[3].position = sf::Vector2f(x * tileSize, (y + 1) * tileSize);

            // Set the color of the vertices to green
            tile[0].color = sf::Color(0, 153, 76);
            tile[1].color = sf::Color(0, 153, 76);
            tile[2].color = sf::Color(0, 153, 76);
            tile[3].color = sf::Color(0, 153, 76);

            if ((y == 7 && x < 4) || (x == 4 && y > 1 && y < 8) || (y == 2 && x > 3 && x < 10) || (x == 9 && y > 2 && y < 9) || (y == 8 && x > 9 && x < 14)
                || (x == 13 && y > 2 && y < 9) || (y == 3 && x > 13))
            {
                tile[0].color = sf::Color(255, 204, 153);
                tile[1].color = sf::Color(255, 204, 153);
                tile[2].color = sf::Color(255, 204, 153);
                tile[3].color = sf::Color(255, 204, 153);
            }

            if ((x == 1 && y == 8) || (x == 3 && y == 6) || (x == 3 && y == 1) || (x == 5 && y == 3) || (x == 8 && y == 3) || (x == 8 && y == 1)
                || (x == 8 && y == 5) || (x == 9 && y == 9) || (x == 10 && y == 6) || (x == 12 && y == 7) || (x == 14 && y == 4))
            {
                tile[0].color = sf::Color(160, 160, 160);
                tile[1].color = sf::Color(160, 160, 160);
                tile[2].color = sf::Color(160, 160, 160);
                tile[3].color = sf::Color(160, 160, 160); 
            }
        }
    }
}


Map::Map(sf::RenderWindow& window)
{
	this->initTileMap();
}

Map::~Map()
{

}

void Map::placeBacteria(Bacteria& bacteria, int x, int y)
{
    sf::Vertex* tile = &tileMap[(x + y * mapWidth) * 4];

    if ((y == 7 && x < 4) || (x == 4 && y > 1 && y < 8) || (y == 2 && x > 3 && x < 10) || (x == 9 && y > 2 && y < 9) || (y == 8 && x > 9 && x < 14)
        || (x == 13 && y > 2 && y < 9) || (y == 3 && x > 13))
    {
        tile[0].set(&bacteria);
        tile[1].setBacteria(&bacteria);
        tile[2].setBacteria(&bacteria);
        tile[3].setBacteria(&bacteria);
    }
    
}

void Map::update()
{

}

void Map::render(sf::RenderTarget& target)
{
    target.draw(this->tileMap);
}
