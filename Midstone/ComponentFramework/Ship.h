#pragma once
#include "Actor.h"
#include "Body.h"
class Ship :
    public Actor
{
    public:
        Body* body;
};

