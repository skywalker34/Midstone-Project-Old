#include "Collision.h"
#include "VMath.h"

bool COLLISION::SphereSphereCollisionDetected(const Sphere* body1, const Sphere* body2) {

	//The stuff straight from Umer.

	bool result = false;
	// Step 1: Find the distance between the two bodies
	// Step 2: Compare the distance to the sum of the radii
	// If distance <= r1 + r2, then result = true
	float sumOfRadii = body1->radius + body2->radius;
	//Find distance between two Bodies
	float distance = VMath::mag(body2->transform - body1->transform); //float distance = sqrt(pow(body2->pos.x - body1->pos.x, 2)) + sqrt(pow(body2->pos.y - body1->pos.y, 2)) + sqrt(pow(body2->pos.z - body1->pos.z, 2));
	if (distance <= sumOfRadii)
	{
		result = true;
	}
	return result;
}

//Not needed because only detection is needed
//void COLLISION::SphereSphereCollisionResponse(Sphere* body1, Sphere* body2) {
//	std::cout << "We have impact baby or in this case... I SEE YOU!" << std::endl;
//}
