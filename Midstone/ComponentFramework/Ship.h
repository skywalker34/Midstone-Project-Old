#pragma once
#include "Actor.h"
#include "Body.h"
class Ship :
    public Actor
{
    public:
        int health;
        int damage;
        float speed = 1;

        Body* body;
        Matrix4 shipModelMatrix;

        Ship() {}
        Ship(int health_, int damage_, float speed_);
        ~Ship();
};

