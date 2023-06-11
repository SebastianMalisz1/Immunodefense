#pragma once
#include "Bullet.h"
class VaccineBullet :
	public Bullet
{
public:
	VaccineBullet();
	VaccineBullet(sf::Vector2f position, float angle1);
	~VaccineBullet();
	virtual void update(sf::RenderTarget* target) override;
	virtual void render(sf::RenderTarget* target) override;
};

