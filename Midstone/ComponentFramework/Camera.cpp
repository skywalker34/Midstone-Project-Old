#include "Camera.h"
#include <MMath.h>

void Camera::SetView(const Quaternion& orientation_, const Vec3& position_) {
	transform.setOrientation(orientation_);
	transform.setPos(position_);
	SetView(transform);
	
}

void Camera::SetView(const Transform t_)
{
	DualQuat T = DQMath::translate(t_.getPos());
	DualQuat R = DQMath::rotate(QMath::conjugate(t_.getOrientation()));
	viewDq = T * R;
}
	
Camera::Camera() {
	projection = MMath::perspective(45.0f, (16.0f / 9.0f), 0.5f, 100.0f);
	transform.setOrientation( Quaternion(1.0f, Vec3(0.0f, 0.0f, 0.0f)));
	transform.setPos(Vec3(0.0f, 0.0f, -10.0));
}

Camera::~Camera() {

}

Matrix4 Camera::GetProjectionMatrix() const {
	return projection;
}

DualQuat Camera::GetViewDQuaternion() const
{
	return DualQuat(viewDq);
}

Matrix4 Camera::GetViewMatrix()const {
	return DQMath::toMatrix4(viewDq);
}
