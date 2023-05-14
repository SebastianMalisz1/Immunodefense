#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Bacteria :
    public Enemy
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float speed;
	int hp;
	int hpMax;
	int damage;
	int gold;


	virtual void initVariables() override;
	virtual void initTexture();
	virtual void initSprite();

public:
	Bacteria();
	Bacteria(float pos_x, float pos_y);
	virtual ~Bacteria();

	virtual void update(Map& map, int x, int y) override;
	virtual void render(sf::RenderTarget* target) override;
};

