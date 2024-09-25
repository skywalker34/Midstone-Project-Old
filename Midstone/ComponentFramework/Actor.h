#pragma once
#include "Model.h"
#include "Transform.h"
//#include "Sphere.h"
class Actor
{
public:	
	//actor is any object in the scene with a visual repersentation
	//Known actors: Planet, Ships(Friendlyship, enemyship)
	//MATHEX::Sphere collider;
	Transform transform;
	Model model;

	Actor() {}
	Actor(Transform transform_, Model model_);
	// Functions:
	// render

    ~Actor();
};

