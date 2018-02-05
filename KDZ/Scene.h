#pragma once

#include "SceneObject.h"
#include "Camera.h"
#include "Renderer.h"

#include <vector>

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	// The Scene class represents a 3D scene that consists of SceneObjects.
	class Scene
	{
	public:
		Scene();
		void renderScene(Renderer ^renderer);
		void addObject(SceneObject obj);
		// test
		void addCube();

	private:
		std::vector<SceneObject> sceneObjects;
		Camera camera;
	};
}