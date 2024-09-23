#pragma once

#include "Texture.h"
#include "Mesh.h"
#include "Shader.h"
class Model
{
public:
	Texture tex;
	Mesh* mesh;
	Shader* shader;
};

