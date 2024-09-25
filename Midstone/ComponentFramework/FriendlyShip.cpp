#include "FriendlyShip.h"

FriendlyShip::FriendlyShip()
{
	body = new Body(&transform, Vec3(), Vec3(), 1);
}

bool FriendlyShip::OnCreate()
{
	printf("Ship Created! \n");
	
	return true;
}

void FriendlyShip::moveToDestination(Vec3 destination_)
{
	destination = destination_;
	if (wouldIntersectPlanet) {
		
		Vec3 axis = VMath::cross(destination, transform.getPos());
		Quaternion newPosition = QMath::angleAxisRotation(1.0f, axis);
		Vec3 direction = QMath::rotate(transform.getPos(), newPosition) - transform.getPos();
		body->vel = speed * VMath::normalize(direction);
	}
	else {
		if (body != nullptr) {
			Vec3 diff = transform.getPos() - destination;
			Vec3 direction = VMath::normalize(diff);
			body->vel = direction * speed;
			
		}


	}
}

bool FriendlyShip::hasReachDestination()
{
	return VMath::mag(body->pos - destination) < 0.1f;
}

FriendlyShip::~FriendlyShip() {}