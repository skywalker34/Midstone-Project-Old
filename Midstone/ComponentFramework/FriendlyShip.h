#pragma once
#include "Ship.h"
#include "Bullet.h"
#include "ShipController.h"
#include <vector>
class FriendlyShip : Ship
{
	std::vector<Bullet> bullets;
	ShipController controller;
};

