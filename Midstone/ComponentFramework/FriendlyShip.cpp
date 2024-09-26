#include "FriendlyShip.h"


FriendlyShip::FriendlyShip()
{
	transform = Transform(Vec3(0.0f, 0.0f, 0.0f), Quaternion(1.0f, Vec3(0.0f, 0.0f, 0.0f)), Vec3(1.0f, 1.0f, 1.0));
	body = new Body(transform, Vec3(), Vec3(), 1);

	
	
	printf("FriendlyShip Constructor: Transform initialized with position (%f, %f, %f)\n", transform.getPos().x, transform.getPos().y, transform.getPos().z);
	
}

bool FriendlyShip::OnCreate()
{
	printf("Ship Created! \n");
	
	return true;
}

void FriendlyShip::Update(const float deltaTime)
{
	
	if (moving) {
		transform = body->Update(deltaTime, transform);
		if (VMath::mag(destination - transform.getPos()) < 0.01) {
			body->vel = Vec3();
			moving = false;
		}
	}
	
}




void FriendlyShip::moveToDestination(Vec3 destination_)
{
	destination = destination_;
	moving = true;
	if (wouldIntersectPlanet) {
		
		Vec3 axis = VMath::cross(destination, transform.getPos());
		Quaternion newPosition = QMath::angleAxisRotation(1.0f, axis);
		Vec3 direction = QMath::rotate(transform.getPos(), newPosition) - transform.getPos();
		body->vel = speed * VMath::normalize(direction);
	}
	else {
		if (body != nullptr) {
			Vec3 diff =  destination - transform.getPos(); //"draw" a vector between the 2 points
			Vec3 direction = VMath::normalize(diff);//"convert" thevector into just a direction (normalize)
			body->vel = direction * speed; //tell the ship to move along that vector
			printf("moveToDestination: Transform position (%f, %f, %f)\n", transform.getPos().x, transform.getPos().y, transform.getPos().z);
			
		}


	}

	
}

bool FriendlyShip::hasReachDestination()
{
	return VMath::mag(body->pos - destination) < 0.1f;
}

FriendlyShip::~FriendlyShip() {}