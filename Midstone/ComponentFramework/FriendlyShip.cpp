#include "FriendlyShip.h"

void FriendlyShip::moveToDestination(Vec3 destination_)
{
	destination = destination_;
	Vec3 axis = VMath::cross(destination, body->pos);
	Quaternion newPosition = QMath::angleAxisRotation(1.0f, axis);
	Vec3 direction = QMath::rotate(body->pos, newPosition) - body->pos;
	body->vel = speed * VMath::normalize(direction);
}

bool FriendlyShip::hasReachDestination()
{
	return VMath::mag(body->pos - destination) < 0.1f;
}

FriendlyShip::~FriendlyShip() {}