#pragma once
#include "Camera.h"
#include "Trackball.h"
#include "Transform.h"
#include <QMath.h>
#include "Actor.h"
#include "Shader.h"
using namespace MATH;

union SDL_Event;



class PlayerController
{
	private:
		
		Actor clickGrid;
		Trackball trackball;
		Transform transform;
		Vec3 forward = Vec3(0.0f,0.0f,-1.0f); //tells the program that into the screen is the negative z axis (might be a better way to do this)
		Vec3 clickPos;
		float speed = 0.5f; //the rate of speed the player can move the camera
		float planeDepth = 0;

	public:
		Camera camera;
		bool has3DClick = false;
		bool OnCreate();
		void OnDestroy();
		void handleEvents(const SDL_Event& sdlEvent);
		void Update(const float deltaTime);
		void Render(Shader* shader) const;
		Vec3 getClickPos();//returns the position of a 3d click
	
};



