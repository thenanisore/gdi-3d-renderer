#include "Scene.h"
#include "Matrix.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	Scene::Scene() : camera() {
		// test code
		addPolygon();
		selectedObject = 0;
	}

	void Scene::renderScene(Renderer ^renderer) {
		renderer->clearScreen();
		renderer->clearZBuffer();
		
		Matrix4 view = camera.getViewMatrix();
		Matrix4 projection;
		if (isPerspective) {
			// TODO: regulate FoV
			projection = Util::perspective(90.0f, renderer->getViewportAspect(), 0.1f, 100.0f);
		}
		else {
			// TODO: set parameters
			projection = Util::orthographic(5, 5, 0.1, 100);
		}

		//renderer->drawAxes(projection * view, false);

		if (!isEmpty()) {
			// get transformation matrices
			Matrix4 model = sceneObjects[selectedObject].getModelMatrix();
			// TODO: render each object
			// pass the current object and a transformation matrix in a renderer
			renderer->renderObject(sceneObjects[selectedObject], projection * view * model, drawWireframe, drawSolid);
		}
	}

	void Scene::addObject(SceneObject obj) {
		sceneObjects.push_back(obj);
		// select the added object
		selectedObject = sceneObjects.size() - 1;
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
		if (!isEmpty()) {
			sceneObjects[selectedObject].reset();
		}
	}

	void Scene::deleteObject() {
		if (!isEmpty()) {
			sceneObjects.erase(sceneObjects.begin() + selectedObject);
		}
	}

	void Scene::selectNextObject() {
		if (!isEmpty() && selectedObject < sceneObjects.size() - 1) {
			selectedObject++;
		}
	}

	void Scene::selectPreviousObject() {
		if (!isEmpty() && selectedObject > 0) {
			selectedObject--;
		}
	}

	// methods to manipulate the camera:

	const float cameraPositionMultiplier = 1.0f;
	void Scene::setCameraPosition(int x_coord, int y_coord, int z_coord) {
		camera.setPosition(Vector3(x_coord, y_coord, z_coord) * cameraPositionMultiplier);
	}

	const float camerRotationMultiplier = 1.0f;
	void Scene::setCameraRotation(float pitch, float yawn, float roll) {
		camera.setRotation(Vector3(pitch, -yawn, roll) * camerRotationMultiplier);
	}

	void Scene::resetCamera() {
		camera.reset();
	}

	void Scene::setProjectionMode(bool perspective) {
		isPerspective = perspective;
	}

	void Scene::setDrawingMode(bool wireframe, bool solid) {
		drawWireframe = wireframe;
		drawSolid = solid;
	}

	bool Scene::isEmpty() {
		return sceneObjects.size() == 0;
	}

	// test
	void Scene::addCube() {
		SceneObject cube(std::vector<Polygon> {
			// front
			Polygon(Vector3(1, -1, 1), Vector3(1, 1, 1), Vector3(-1, 1, 1)),
			Polygon(Vector3(-1, 1, 1), Vector3(-1, -1, 1), Vector3(1, -1, 1)),
			// right
			Polygon(Vector3(1, -1, 1), Vector3(1, -1, -1), Vector3(1, 1, -1)),
			Polygon(Vector3(1, 1, -1), Vector3(1, 1, 1), Vector3(1, -1, 1)),
			// back
			Polygon(Vector3(1, 1, -1), Vector3(1, -1, -1), Vector3(-1, -1, -1)),
			Polygon(Vector3(-1, -1, -1), Vector3(-1, 1, -1), Vector3(1, 1, -1)),
			// left
			Polygon(Vector3(-1, -1, 1), Vector3(-1, 1, -1), Vector3(-1, -1, -1)),
			Polygon(Vector3(-1, -1, 1), Vector3(-1, 1, 1), Vector3(-1, 1, -1)),
			// top
			Polygon(Vector3(1, 1, 1), Vector3(1, 1, -1), Vector3(-1, 1, -1)),
			Polygon(Vector3(-1, 1, -1), Vector3(-1, 1, 1), Vector3(1, 1, 1)),
			// bottom
			Polygon(Vector3(-1, -1, -1), Vector3(1, -1, -1), Vector3(1, -1, 1)),
			Polygon(Vector3(-1, -1, -1), Vector3(1, -1, 1), Vector3(1, -1, -1))
		});
		sceneObjects.push_back(cube);
		selectedObject = sceneObjects.size() - 1;
	}

	void Scene::addPolygons() {
		SceneObject polygon(std::vector<Polygon> {
			Polygon(Vector3(0, 0, 0), Vector3(1, 0, 0), Vector3(0, 1, 0)),
			Polygon(Vector3(0, 0, 2), Vector3(1, 0, 2), Vector3(0, 1, 2)),
			Polygon(Vector3(0, 0, -2), Vector3(1, 0, -2), Vector3(0, 1, -2)),
		});
		sceneObjects.push_back(polygon);
		selectedObject = sceneObjects.size() - 1;
	}

	void Scene::addPolygon() {
		SceneObject polygon(std::vector<Polygon> {
			Polygon(Vector3(0, 0, 0), Vector3(1, 0, 0), Vector3(0, 1, 0)),
		});
		sceneObjects.push_back(polygon);
		selectedObject = sceneObjects.size() - 1;
	}
}