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

		//Inherited:
		// Transform transform
		// Model model
		//health
		//damage
		//speed
		//body
		//modelmatrix
		std::vector<Bullet> bullets;
		ShipController controller;
		Vec3 destination = Vec3(0, 0, 5.0f);

		FriendlyShip();
		bool OnCreate();
		bool wouldIntersectPlanet = false;
		void moveToDestination(Vec3 destination);
		bool hasReachDestination();

		~FriendlyShip();
};

