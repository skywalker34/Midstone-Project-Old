#ifndef SPHERE_H
#define SPHERE_H
#include <Vector.h> /// This is in GameDev
using namespace MATH; 

/// Just forward declair these classes so I can define a pointer to them
/// Used later in the course
class Mesh;
class Texture;

class Sphere {
public:
	Sphere();
	Sphere(Vec3 pos_, Vec3 vel_, Vec3 acc_, float mass_);
    ~Sphere();
// private: /// Physics stuff
	Vec3 pos;
	Vec3 vel;
	Vec3 accel;
	float mass;
private: /// Graphics stuff 
	//Mesh *mesh;
	//Texture *texture;
	
public:
	bool OnCreate();
	void OnDestroy();
	void Update(float deltaTime);
	void Render() const;
	//void ApplyForce(Vec3 force);
	//void setAccel(const Vec3 &accel_) { accel = accel_;}
};

#endif
