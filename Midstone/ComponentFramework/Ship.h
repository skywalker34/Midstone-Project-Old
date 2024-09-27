#pragma once
#include "Actor.h"
#include "Body.h"
class Body;

class Ship :
    public Actor
{
    public:
        int health;
        int damage;
        float speed = 1;

        Body* body = nullptr;
        Matrix4 shipModelMatrix;

        Ship() {}
        Ship(int health_, int damage_, float speed_);
        bool OnCreate();
        //virtual void moveToPosition();
        ~Ship();
};

