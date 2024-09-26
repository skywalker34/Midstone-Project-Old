#include "Model.h"

Model::Model()
{
}

Model::Model(std::string meshName_)
{
	meshName =  meshName_;
	fileName = filePath + meshName;
	std::cout << fileName;
}

bool Model::OnCreate()
{
	
	mesh = new Mesh(fileName.c_str());
	
	if(mesh->OnCreate() == false) return false;

	return true;
	
}
