#include "Sphere.h"

Sphere::Sphere(): pos{}, vel{}, accel{}, mass{0.0f}, mesh{nullptr},texture{nullptr} {
}

Sphere::Sphere(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_)
{
	pos = pos_;
	vel = vel_;
	accel = accel_;
	mass = mass_;
}

Sphere::~Sphere() {}

void Sphere::Update(float deltaTime) {
	/// From 1st semester physics class
	pos += vel * deltaTime + 0.5f * accel * deltaTime * deltaTime;
	vel += accel * deltaTime;
}

bool Sphere::OnCreate() {
	return true;
}

void Sphere::OnDestroy() {
}

void Sphere::Render() const {
}

//void Sphere::ApplyForce(Vec3 force) {
//	accel = force / mass;
//}
