#include "PlayerController.h"
#include <SDL.h>

#include <DQMath.h>
#include <Plane.h>



bool PlayerController::OnCreate()
{
	//here for future improvements
	transform.setPos(Vec3(0, 0, -10));
	camera.SetView(transform);
	return true;
	
}

void PlayerController::handleEvents(const SDL_Event& sdlEvent)
{
	trackball.HandleEvents(sdlEvent);
	transform.setOrientation(trackball.getQuat()); //trackball so viewer can "turn their head"

	Vec3 direction = QMath::rotate(-forward, transform.getOrientation()); //gets the direction the camera is facing
	//direction.print("Direction: ");
	Vec3 v;//temporary
	switch (sdlEvent.type) {
	case SDL_KEYDOWN: //code that allows the user to move the camera around
		switch (sdlEvent.key.keysym.scancode) {
		case SDL_SCANCODE_W:
			//transform.setPos(transform.getPos() + (-direction * speed));
			//^^^THIS should work, no idea why it doesn't

			//	below works *marginally* better (still jank af)
			v = transform.getPos();
			v += (VMath::normalize(-direction) * speed);
			transform.setPos(v);
			break;

		case SDL_SCANCODE_S:
			//transform.setPos(transform.getPos() + (direction * speed));


			v = transform.getPos();
			v += (direction * speed);

			transform.setPos(v);
			break;

			//future for strafing movement
		case SDL_SCANCODE_A:

			break;

		case SDL_SCANCODE_D:

			break;



		}
		break;

	case SDL_MOUSEBUTTONDOWN:

	{
		IHave3DClick = true;
		Vec4 mousePosPixelSpace = Vec4(sdlEvent.button.x, sdlEvent.button.y, 0, 1);

		Vec4 mousePosNDCSpace = MMath::inverse(MMath::viewportNDC(1280, 720)) * mousePosPixelSpace;
		// Let's get the front of the NDC box
		mousePosNDCSpace.z = -1.0f;

		Vec4 mousePosCameraSpace = MMath::inverse(camera.GetProjectionMatrix()) * mousePosNDCSpace;
		// Divide out the w component
		mousePosCameraSpace = mousePosCameraSpace / mousePosCameraSpace.w;

		Vec4 mousePosWorldSpace = MMath::inverse(MATHEX::DQMath::toMatrix4(camera.GetViewDQuaternion())) * mousePosCameraSpace;

		// Make a line from the camera position to the mouse
		// Using the join of two points
		DualQuat line = transform.getPos() & mousePosWorldSpace;

		// Make a plane based off scrollwheel
		Plane plane = Plane(0, 0, 1, -(-planeDepth));

		// intersection point is the meet of line and plane
		Vec4 intersection = line ^ plane;

		// Divide out the w component
		intersection = intersection / intersection.w;


		intersection.print("3D click at: ");
	}
	break;

	case SDL_MOUSEBUTTONUP:
		break;

	case SDL_MOUSEWHEEL:
		planeDepth += sdlEvent.wheel.preciseY;
		//plane depth increases if the mouse is wheeled up (by the amount the mouse is wheeled)
		//plane depth decreases if the mouse is wheeled down (by the amount the mouse is wheeled)


		break;

		
	}

	camera.SetView(transform);

}
