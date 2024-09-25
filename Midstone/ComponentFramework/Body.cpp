#include "Body.h"

//Body::Body(): pos{}, vel{}, accel{}, mass{0.0f}, mesh{nullptr},texture{nullptr} {
//}

Body::Body(Transform* tran, Vec3 vel_, Vec3 accel_, float mass_)
{
	
	vel = vel_;
	accel = accel_;
	mass = mass_;
}

Body::~Body() {}

void Body::Update(float deltaTime) {
	/// From 1st semester physics class
	transform->setPos(transform->getPos() + vel * deltaTime + 0.5f * accel * deltaTime * deltaTime);
	vel += accel * deltaTime;
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

