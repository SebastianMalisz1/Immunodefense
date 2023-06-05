#pragma once
#include "Bullet.h"
class PelletBullet :
    public Bullet
{
public:
	PelletBullet();
	PelletBullet(sf::Vector2f position, float angle1);
	~PelletBullet();
	virtual void update(sf::RenderTarget* target) override;
	virtual void render(sf::RenderTarget* target) override;
};
