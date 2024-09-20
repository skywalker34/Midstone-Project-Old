#pragma once
#include "Model.h"
#include "Transform.h"
#include "Sphere.h"
class Actor
{
public:
	MATHEX::Sphere collider;
	Transform transform;
	Model model;
};

