#include "Body.h"

//Body::Body(): pos{}, vel{}, accel{}, mass{0.0f}, mesh{nullptr},texture{nullptr} {
//}

//Body::Body(Transform& tran, Vec3 vel_, Vec3 accel_, float mass_, int *test)
//{
//	transform = tran;
//	vel = vel_;
//	accel = accel_;
//	mass = mass_;
//	
//
//	paul = test;
//	*test += 1;
//	*paul += 1;
//	
//}

Body::~Body() {}

void Body::Update(float deltaTime) {

	transform.getPos().print("AAAAAAAAAAAAAAAAAAAAAAAAH ");
	transform.setPos(Vec3(1, 1, 1));
	/*printf("Before Update: Transform position (%f, %f, %f)\n", transform->getPos().x, transform->getPos().y, transform->getPos().z);
	Vec3 v = transform->getPos();
	transform->setPos(v + vel * deltaTime + 0.5f * accel * deltaTime * deltaTime);
	printf("After Update: Transform position (%f, %f, %f)\n", transform->getPos().x, transform->getPos().y, transform->getPos().z);
	vel.print("Ship Velocity: ");
	transform->getPos().print("Ship Position: ");
	vel += accel * deltaTime;*/
}

void Body::ApplyForce(Vec3 force) {
	accel = force / mass;
}

bool Body::OnCreate() {
	return true;
}

void Body::OnDestroy() {
}

void Body::Render() const {
}

