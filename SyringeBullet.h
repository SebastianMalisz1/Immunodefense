#pragma once
#include "Bullet.h"

class SyringeBullet :
    public Bullet
{
public:
	SyringeBullet();
	SyringeBullet(sf::Vector2f position, float angle1);
	~SyringeBullet();
	virtual void update(sf::RenderTarget* target) override;
	virtual void render(sf::RenderTarget* target) override;
};

