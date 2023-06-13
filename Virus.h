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

class Virus :
	public Enemy
{
private:
	//sf::Sprite sprite;
	//sf::Texture texture;

	//float speedX;
	//float speedY;
	//int hp;
	//int hpMax;
	//int damage;
	//int gold;

	//Mapa* map;
public:
	virtual void initVariables() override;
	virtual void initTexture() override;
	virtual void initSprite() override;



	Virus(float pos_x, float pos_y);
	virtual ~Virus();

	//const sf::FloatRect getBounds() const;
	virtual void loseHp(const int value) override;
	virtual const int& getDamage() const override;
	virtual void upgrade() override;
	virtual void upgrade2() override;
	virtual void upgrade3() override;
	virtual void update(Mapa* map) override;
	virtual void render(sf::RenderTarget* target) override;
};

