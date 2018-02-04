#pragma once

#include "SceneObject.h"
#include "Camera.h"

#include <vector>

// The Scene class represents a 3D scene that consists of SceneObjects.
class Scene
{
public:
	Scene();

private:
	std::vector<SceneObject> sceneObjects;
	Camera camera;
};
