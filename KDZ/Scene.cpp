#include "Scene.h"
#include "Matrix.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	Scene::Scene() : camera(Vector3(0, 0, 5)) {
		// test code
		addCube();
		selectedObject = 0;
	}

	void Scene::renderScene(Renderer ^renderer) {
		renderer->clearZBuffer();
		renderer->clearScreen();
		// TODO: draw axes/grid

		// get transformation matrices
		Matrix4 model = sceneObjects[selectedObject].getModelMatrix();
		Matrix4 view = camera.getViewMatrix();
		Matrix4 projection = Util::perspective(45.0f, renderer->getViewportAspect(), 0.1f, 100.0f);

		// pass the current object and a transformation matrix in a renderer
		renderer->renderObject(sceneObjects[selectedObject], projection * view * model); 
	}

	void Scene::addObject(SceneObject obj) {
		sceneObjects.push_back(obj);
	}

	// methods to manipulate objects:

	const float positionMultiplier = 0.1f;
	void Scene::setObjectPosition(int x_coord, int y_coord, int z_coord) {
		sceneObjects[selectedObject].setPosition(Vector3(x_coord, y_coord, z_coord) * positionMultiplier);
	}

	const float rotationMultiplier = 1.0f;
	void Scene::setObjectRotation(float x_angle, float y_angle, float z_angle) {
		sceneObjects[selectedObject].setRotation(Vector3(x_angle, y_angle, z_angle) * rotationMultiplier);
	}

	const float scaleMultiplier = 0.1f;
	void Scene::setObjectScale(int x_scale, int y_scale, int z_scale) {
		sceneObjects[selectedObject].setScale(Vector3(x_scale, y_scale, z_scale) * scaleMultiplier);
	}

	void Scene::setObjectReflection(bool xy, bool xz, bool yz) {
		sceneObjects[selectedObject].setReflection(xy, xz, yz);
	}

	void Scene::resetObject() {
		sceneObjects[selectedObject].reset();
	}

	void Scene::deleteObject() {
		// TODO
	}

	void Scene::selectNextObject() {
		if (selectedObject < sceneObjects.size()) {
			selectedObject++;
		}
	}

	void Scene::selectPreviousObject() {
		if (selectedObject > 0) {
			selectedObject--;
		}
	}

	// methods to manipulate the camera:

	const float cameraPositionMultiplier = 1.0f;
	void Scene::setCameraPosition(int x_coord, int y_coord, int z_coord) {
		camera.setPosition(Vector3(x_coord, y_coord, z_coord) * (1 + cameraPositionMultiplier));
	}

	const float camerRotationMultiplier = 1.0f;
	void Scene::setCameraRotation(float pitch, float yawn, float roll) {
		camera.setRotation(Vector3(pitch, yawn, roll) * camerRotationMultiplier);
	}

	void Scene::resetCamera() {
		camera.reset();
	}

	bool Scene::isEmpty() {
		return sceneObjects.size() == 0;
	}

	// test
	void Scene::addCube() {
		SceneObject cube(std::vector<Polygon> {
			// front
			Polygon(std::vector<Vector3> { Vector3(1, -1, 1), Vector3(1, 1, 1), Vector3(-1, 1, 1) }),
			Polygon(std::vector<Vector3> { Vector3(-1, 1, 1), Vector3(-1, -1, 1), Vector3(1, -1, 1) }),
			// right
			Polygon(std::vector<Vector3> { Vector3(1, -1, 1), Vector3(1, -1, -1), Vector3(1, 1, -1) }),
			Polygon(std::vector<Vector3> { Vector3(1, 1, -1), Vector3(1, 1, 1), Vector3(1, -1, 1) }),
			// back
			Polygon(std::vector<Vector3> { Vector3(1, 1, -1), Vector3(1, -1, -1), Vector3(-1, -1, -1) }),
			Polygon(std::vector<Vector3> { Vector3(-1, -1, -1), Vector3(-1, 1, -1), Vector3(1, 1, -1) }),
			// left
			Polygon(std::vector<Vector3> { Vector3(-1, -1, 1), Vector3(-1, 1, -1), Vector3(-1, -1, -1) }),
			Polygon(std::vector<Vector3> { Vector3(-1, -1, 1), Vector3(-1, 1, 1), Vector3(-1, 1, -1) }),
			// top
			Polygon(std::vector<Vector3> { Vector3(1, 1, 1), Vector3(1, 1, -1), Vector3(-1, 1, -1) }),
			Polygon(std::vector<Vector3> { Vector3(-1, 1, -1), Vector3(-1, 1, 1), Vector3(1, 1, 1) }),
			// bottom
			Polygon(std::vector<Vector3> { Vector3(-1, -1, -1), Vector3(1, -1, -1), Vector3(1, -1, 1) }),
			Polygon(std::vector<Vector3> { Vector3(-1, -1, -1), Vector3(1, -1, 1), Vector3(1, -1, -1) })
		});
		sceneObjects.push_back(cube);
	}
}