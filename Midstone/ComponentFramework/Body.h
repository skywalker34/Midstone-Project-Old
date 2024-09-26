#ifndef BODY_H
#define BODY_H
#include <Vector.h> /// This is in GameDev
#include "Transform.h"
using namespace MATH; 

/// Just forward declair these classes so I can define a pointer to them
/// Used later in the course



class Body {
public:
    Body();
	Body(Transform& tran, Vec3 vel_, Vec3 acc_, float mass_)
		: transform(tran), vel(vel_), accel(acc_), mass(mass_) {}
    ~Body();
// private: /// Physics stuff
	Vec3 pos;
	Vec3 vel;
	Vec3 accel;
	Transform& transform;

	int* paul;
	float mass;
private: /// Graphics stuff 
	
	
public:
	bool OnCreate();
	void OnDestroy();
	void Update(float deltaTime);
	void Render() const;
	void ApplyForce(Vec3 force);
	void setAccel(const Vec3 &accel_) { accel = accel_;}
};

#endif
