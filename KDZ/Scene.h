/*
* Студент: Иванов Олег Владимирович
* Группа: 141/1, 4 курс
* КДЗ #1, Вариант 1: 3D-сцена в GDI.
*
* Класс Scene: трёхмерная сцена, содержащая камеру, объекты, источник света.
*/

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

		// methods to manipulate objects;

		void setObjectPosition(int x_coord, int y_coord, int z_coord);
		void setObjectRotation(float x_angle, float y_angle, float z_angle);
		void setObjectReflection(bool xy, bool xz, bool yz);
		void setObjectScale(int x_scale, int y_scale, int z_scale);

		Vector3 getObjectPosition(bool worldCoords) const;
		Vector3 getObjectRotation(bool worldCoords) const;
		Vector3 getObjectReflection() const;
		Vector3 getObjectScale(bool worldCoords) const;

		void resetObject();
		void deleteObject();
		void selectNextObject();
		void selectPreviousObject();

		// methods to manipulate camera:

		void setCameraPosition(int x_coord, int y_coord, int z_coord);
		void setLightParams(float _ambient, float _diffuse, float _specular);
		Vector3 getLightParams();
		void setCameraRotation(float pitch, float yawn, float roll);
		Vector3 getCameraPosition(bool worldCoords) const;
		Vector3 getCameraRotation(bool worldCoords) const;

		void resetCamera();

		// methods to manipulate lighting:

		Vector3 getLightPosition(bool worldCoords);
		void setLightPosition(int x_coord, int y_coord, int z_coord);
		void setLightColor(Color^ lightColor);
		void setLightOn(bool isOn);
		void setLightMode(LightMode _mode);
		Color getLightColor();
		bool isLightOn();
		LightMode getLightMode();
		void resetLighting();

		// material parameters manipulation:

		void setMaterialParams(int _ambi, int _diff, int _spec, int _shine);
		void setMaterialColor(Color ^col);
		Vector4 getMaterialParams();
		Color getMaterialColor();
		void resetMaterial();

		// textures manipulation:

		void setTexture(int iTex);
		void removeTexture();
		int getTexture();

		// Sets projection mode: perspective if the parameter is true, orthographics otherwise.
		void setProjectionMode(bool perspective);
		// Sets drawing mode flags: wireframe and/or solid.
		void setDrawingMode(bool wireframe, bool solid);
		void setCulling(bool cull);
		// Returns true is the scene contains no objects.
		bool isEmpty();
		bool isSelectedFirst();
		bool isSelectedLast();
		bool isPerspective();
		bool isWireframeMode();
		bool isSolidMode();
		bool isCulling();
		unsigned int objectCount();
		unsigned int getSelected();

		// Object placement.
		void addObject(SceneObject obj);
		bool fromFile(String ^file);

	private:
		Light lightSource;
		Camera camera;
		std::vector<SceneObject> sceneObjects;
		int selectedObject;
		bool perspective;
		bool faceCull;
		bool drawWireframe;
		bool drawSolid;
	};
}