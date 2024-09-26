#include "Model.h"

Model::Model()
{
}

Model::Model(std::string meshName_)
{
	meshName =  meshName_;
	fileName = (filePath + meshName).c_str();
}

bool Model::OnCreate()
{
	
	mesh = new Mesh("meshes/Plane.obj");
	
	if(mesh->OnCreate() == false) return false;

	return true;
	
}
