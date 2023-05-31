#pragma once

#include <time.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
   
#include "Map.h"
#include "Enemy.h"

class Bacteria :
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
//	Mapa* map;
    
	 virtual void initVariables() override;
	 virtual void initTexture() override;
	 virtual void initSprite() override;
    

public:
	Bacteria(float pos_x, float pos_y);
	virtual ~Bacteria();

	//const sf::FloatRect getBounds() const;
	virtual void update(Mapa* map) override;
	virtual void render(sf::RenderTarget* target) override;
};

