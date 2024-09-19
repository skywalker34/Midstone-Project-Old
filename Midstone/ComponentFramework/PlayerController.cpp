#include "PlayerController.h"
#include <SDL.h>
#include "QMath.h"	

bool PlayerController::OnCreate()
{
	//here for future improvements
	transform.setPos(Vec3(0, 0, -10));
	return true;
	
}

void PlayerController::handleEvents(const SDL_Event& sdlEvent)
{
	trackball.HandleEvents(sdlEvent);
	transform.setOrientation(trackball.getQuat()); //trackball so viewer can "turn their head"

	Vec3 direction = QMath::rotate(-forward, transform.getOrientation()); //gets the direction the camera is facing
	direction.print("Direction: ");
	Vec3 v;//temporary
	switch (sdlEvent.type) {
	case SDL_KEYDOWN: //code that allows the user to move the camera around
		switch (sdlEvent.key.keysym.scancode) {
		case SDL_SCANCODE_W:
			//transform.setPos(transform.getPos() + (-direction * speed));
			//^^^THIS should work, no idea why it doesn't

			//	below works *marginally* better (still jank af)
			v = transform.getPos();
			v += (-direction * speed);
			
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
	}

	camera.SetView(transform);
	
}
