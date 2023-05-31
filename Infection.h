#pragma once
#include "Enemy.h"
#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Map.h"
class Mapa;

class Infection :
	public Enemy
{
//private:
//	sf::Sprite sprite;
//	sf::Texture texture;
//
//	float speedX;
//	float speedY;
//	int hp;
//	int hpMax;
//	int damage;
//	int gold;
//
//	Mapa* map;

	virtual void initVariables() override;
	virtual void initTexture() override;
	virtual void initSprite() override;


public:
	Infection(float pos_x, float pos_y);
	virtual ~Infection();

	//const sf::FloatRect getBounds() const;
	virtual void update(Mapa* map) override;
	virtual void render(sf::RenderTarget* target) override;
};

