#include "Ship.h"

Ship::Ship(int health_, int damage_, float speed_) {
	health = health_;
	damage = damage_;
	speed = speed_;

	body = new Body(&transform, Vec3(), Vec3(), 1);
}


Ship::~Ship() {}