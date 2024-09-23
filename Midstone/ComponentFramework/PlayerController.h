#pragma once
#include "Camera.h"
#include "Trackball.h"
#include "Transform.h"
#include <QMath.h>
using namespace MATH;

union SDL_Event;



class PlayerController
{
	private:
		
		Trackball trackball;
		Transform transform;
		Vec3 forward = Vec3(0.0f,0.0f,-1.0f); //tells the program that into the screen is the negative z axis (might be a better way to do this)
		float speed = 0.5f; //the rate of speed the player can move the camera
		float planeDepth = 0;

	public:
		Camera camera;
		bool IHave3DClick;
		bool OnCreate();
		void OnDestroy();
		void handleEvents(const SDL_Event& sdlEvent);
	
};



