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

	float speed;
	int hp;
	int hpMax;
	int damage;
	int gold;


	virtual void initVariables();
	virtual void initTexture();
	virtual void initSprite();

public:
	Enemy();
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	virtual void update();
	virtual void render(sf::RenderTarget* target);
};
