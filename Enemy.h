#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Map.h"


class Enemy
{
public:
	sf::Sprite sprite;
	sf::Texture texture;

    float speedX;
    float speedY;
	int hp;
	int hpMax;
	int damage;
	int gold;





    virtual void initVariables(){};
    virtual void initTexture(){};
    virtual void initSprite(){};

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
      {1, 1, 1, 1, 2, 1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 2, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 2, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
    };

    Enemy();
	virtual ~Enemy();

	virtual const sf::FloatRect getBounds() const;
	virtual const sf::Vector2f getPos() const;
    virtual const int& getDamage() const;
    virtual void loseHp(const int value);
    virtual void upgrade();
    virtual void upgrade2();
    virtual void upgrade3();
    virtual void update(Mapa* map){};
	virtual void render(sf::RenderTarget* target);

   
  
};
