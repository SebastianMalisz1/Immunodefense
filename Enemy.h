#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Enemy
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

    float speedX;
    float speedY;
	int hp;
	int hpMax;
	int damage;
	int gold;

	virtual void initVariables();
	virtual void initTexture();
	virtual void initSprite();

public:
    const int initTab[19][10] = {
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 2, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
      {1, 1, 1, 1, 0, 2, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 1, 2, 1, 1},
      {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 2, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 2, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
      {1, 1, 1, 1, 2, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 0, 2, 1},
      {1, 1, 1, 1, 2, 1, 1, 0, 0, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
    };

    Enemy();
	virtual ~Enemy();

	virtual const sf::FloatRect getBounds() const;

	virtual void render(sf::RenderTarget* target);

   
  
};
