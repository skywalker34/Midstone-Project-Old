#include "Transform.h"

Transform::Transform(Vec3 _position, Quaternion _orientation, Vec3 _scale)
{
	position = _position;
	orientation = _orientation;
	scale = _scale;
}

Transform::Transform()
{
	//default everything to the origin
	position = Vec3(0.0f, 0.0f, 0.0f);
	//default to identity
	orientation = Quaternion(1.0f, Vec3(0.0f, 0.0f, 0.0f));
	//default exact scale
	scale = Vec3(1.0f, 1.0f, 1.0);

}

void Transform::setPos(Vec3 p)
{
	position = p;
}

void Transform::setOrientation(Quaternion q)
{
	orientation = q;
}

void Transform::setScale(Vec3 s)
{
	scale = s;
}

Vec3 Transform::getPos() const
{
	return position;
}

Vec3 Transform::getScale() const
{
	return scale;
}

Quaternion Transform::getOrientation() const
{
	return orientation;
}
