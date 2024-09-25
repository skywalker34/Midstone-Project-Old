#pragma once
#include "Ship.h"
#include "Bullet.h"
#include "ShipController.h"
#include <vector>
#include <QMath.h>
#include <VMath.h>
class FriendlyShip : 
	public Ship
{
	public:
		std::vector<Bullet> bullets;
		ShipController controller;
		Vec3 destination = Vec3(0, 0, 5.0f);

		FriendlyShip() {}
		bool wouldIntersectPlanet;
		void moveToDestination(Vec3 destination);
		bool hasReachDestination();

		~FriendlyShip();
};

