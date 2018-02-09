#include "Scene.h"
#include "Util.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	const float positionMultiplier = 0.1f;
	const float rotationMultiplier = 1.0f;
	const float scaleMultiplier = 0.1f;
	const float cameraPositionMultiplier = 1.0f;
	const float camerRotationMultiplier = 1.0f;

	Scene::Scene() : camera() {
		// test code
		//addPolygon();
		addCube();
		//addPolygons();
		selectedObject = 0;
		lightPos = camera.getPosition();
	}

	void Scene::renderScene(Renderer ^renderer) {
		renderer->clearScreen();
		renderer->clearZBuffer();
		renderer->setFaceCulling(faceCull);
		
		// calculate matrices
		Matrix4 view = camera.getViewMatrix();
		Matrix4 projection;
		if (isPerspective()) {
			// TODO: regulate FoV
			projection = Util::perspective(60.f, renderer->getViewportAspect(), 0.1f, 100.f);
			renderer->setProjection(true);
		}
		else {
			projection = Util::orthographic(5, 5, 0.1f, 100.f);
			renderer->setProjection(false);
		}

		//renderer->drawAxes(projection * view, false);
		if (!isEmpty()) {
			for (const SceneObject &object : sceneObjects) {
				// get transformation matrix
				Matrix4 model = object.getModelMatrix();
				// notify the renderer if the current object is selected
				renderer->isSelectedObject = (&sceneObjects[selectedObject] == &object);
				// pass the current object and transformation matrices in the renderer
				renderer->renderObject(object, model, view, projection, camera.getPosition(), 
					lightPos, drawWireframe, drawSolid);
				renderer->isSelectedObject = false;
			}
		}
	}

	// methods to manipulate objects:

	void Scene::setObjectPosition(int x_coord, int y_coord, int z_coord) {
		sceneObjects[selectedObject].setPosition(Vector3(x_coord, y_coord, z_coord) * positionMultiplier);
	}

	void Scene::setObjectRotation(float x_angle, float y_angle, float z_angle) {
		sceneObjects[selectedObject].setRotation(Vector3(x_angle, y_angle, z_angle) * rotationMultiplier);
	}

	void Scene::setObjectScale(int x_scale, int y_scale, int z_scale) {
		sceneObjects[selectedObject].setScale(Vector3(x_scale, y_scale, z_scale) * scaleMultiplier);
	}

	void Scene::setObjectReflection(bool xy, bool xz, bool yz) {
		sceneObjects[selectedObject].setReflection(xy, xz, yz);
	}

	Vector3 Scene::getObjectPosition(bool worldCoords) const {
		return sceneObjects[selectedObject].getPosition() / (worldCoords ? 1.f : positionMultiplier);
	}

	Vector3 Scene::getObjectRotation(bool worldCoords) const {
		return sceneObjects[selectedObject].getRotation() / (worldCoords ? 1.f : rotationMultiplier);
	}

	Vector3 Scene::getObjectReflection() const {
		return sceneObjects[selectedObject].getReflection();
	}

	Vector3 Scene::getObjectScale(bool worldCoords) const {
		return sceneObjects[selectedObject].getScale() / (worldCoords ? 1.f : scaleMultiplier);
	}

	Vector3 Scene::getCameraPosition(bool worldCoords) const {
		return camera.getPosition() / (worldCoords ? 1.f : cameraPositionMultiplier);
	}

	Vector3 Scene::getCameraRotation(bool worldCoords) const {
		return camera.getRotation() / (worldCoords ? 1.f : camerRotationMultiplier);
	}

	void Scene::resetObject() {
		if (!isEmpty()) {
			sceneObjects[selectedObject].reset();
		}
	}

	void Scene::addObject(SceneObject &obj) {
		sceneObjects.push_back(obj);
		// select the added object
		selectedObject = sceneObjects.size() - 1;
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

	void Scene::setCameraPosition(int x_coord, int y_coord, int z_coord) {
		camera.setPosition(Vector3(x_coord, y_coord, z_coord) * cameraPositionMultiplier);
	}

	void Scene::setCameraRotation(float pitch, float yawn, float roll) {
		camera.setRotation(Vector3(pitch, -yawn, roll) * camerRotationMultiplier);
	}

	void Scene::resetCamera() {
		camera.reset();
	}

	Vector3 Scene::getLightPosition() {
		return lightPos;
	}

	void Scene::setLightPosition(int x_coord, int y_coord, int z_coord) {
		lightPos = Vector3(x_coord, y_coord, z_coord);
	}

	void Scene::resetLighting() {
		// TODO: reset lighting
	}

	void Scene::setProjectionMode(bool _perspective) {
		perspective = _perspective;
	}

	void Scene::setDrawingMode(bool wireframe, bool solid) {
		drawWireframe = wireframe;
		drawSolid = solid;
	}

	void Scene::setCulling(bool cull) {
		faceCull = cull;
	}

	bool Scene::isEmpty() {
		return sceneObjects.size() == 0;
	}

	bool Scene::isSelectedFirst() {
		return selectedObject == 0 && !isEmpty();
	}

	bool Scene::isSelectedLast() {
		return selectedObject == sceneObjects.size() - 1 && !isEmpty();
	}

	bool Scene::isPerspective() {
		return perspective;
	}

	bool Scene::isWireframeMode() {
		return drawWireframe;
	}

	bool Scene::isSolidMode() {
		return drawSolid;
	}

	bool Scene::isCulling() {
		return faceCull;
	}

	unsigned int Scene::objectCount() {
		return sceneObjects.size();
	}

	unsigned int Scene::getSelected() {
		return selectedObject;
	}
	bool Scene::fromFile(String ^ file) {
		String^ delimStr = "\r\n";
		array<Char>^ delimiter = delimStr->ToCharArray();
		array<String^>^ lines = file->Split(delimiter);
		// parse each line
		std::vector<Vector3> vertices;
		std::vector<Vector3> colors;
		std::vector<Vector3> indices;
		for (int i = 0; i < lines->Length; i++) {
			String^ trimmed = lines[i]->Trim();
			// discard empty lines and comments
			if (!String::IsNullOrWhiteSpace(trimmed) && trimmed[0] != '#') {
				// parse
				// TODO: exception handling
				Vector3 data;
				switch (trimmed[0]) {
				case 'v':
					// vertex
					data = Util::parseVec3(trimmed->Substring(2));
					vertices.push_back(data);
					break;
				case 'c':
					// color
					data = Util::parseVec3(trimmed->Substring(2));
					colors.push_back(data);
					break;
				case 'f':
					// polygon indices
					data = Util::parseVec3(trimmed->Substring(2));
					indices.push_back(data);
					break;
				default:
					// do nothing?
					continue;
				}
			}
		}
		// construct a SceneObject
		SceneObject newObj;
		for (int i = 0; i < indices.size(); i++) {
			indices[i] = indices[i] - 1;
			newObj.addPolygon(GL::Polygon(
				vertices[(int)indices[i].x],
				vertices[(int)indices[i].y],
				vertices[(int)indices[i].z]
			));
			if (colors.size() == vertices.size()) {
				newObj.polygons[newObj.polygons.size() - 1].setColors(
					colors[(int)indices[i].x],
					colors[(int)indices[i].y],
					colors[(int)indices[i].z]
				);
			}
		}
		addObject(newObj);

		return true;
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
			Polygon(Vector3(1, -1, 1), Vector3(-1, -1, 1), Vector3(-1, -1, -1))
		});
		cube.setPolygonColor(std::vector<Vector4> {
			// front
			Vector4(1.f, 0.f, 0.f, 1.f), Vector4(1.f, 0.f, 0.f, 1.f),
			// right
			Vector4(0.f, 1.f, 0.f, 1.f), Vector4(0.f, 1.f, 0.f, 1.f),
			// back
			Vector4(0.f, 0.f, 1.f, 1.f), Vector4(0.f, 0.f, 1.f, 1.f),
			// left
			Vector4(1.f, 0.f, 1.f, 1.f), Vector4(1.f, 0.f, 1.f, 1.f),
			// top
			Vector4(1.f, 1.f, 0.f, 1.f), Vector4(1.f, 1.f, 0.f, 1.f),
			// bottom
			Vector4(0.f, 1.f, 1.f, 1.f), Vector4(0.f, 1.f, 1.f, 1.f)
		});
		sceneObjects.push_back(cube);
		selectedObject = sceneObjects.size() - 1;
	}

	void Scene::addPolygons() {
		SceneObject polygon(std::vector<Polygon> {
			Polygon(Vector3(0, 0, 2), Vector3(1, 0, 2), Vector3(0, 1, 2)),
			Polygon(Vector3(0, 0, 0), Vector3(1, 0, 0), Vector3(0, 1, 0)),
			Polygon(Vector3(1, 0, -2), Vector3(2, 0, -2), Vector3(1, 1, -2)),
		});
		polygon.polygons[0].setColors(Vector3(1, 0, 0), Vector3(1, 0, 0), Vector3(1, 0, 0));
		polygon.polygons[1].setColors(Vector3(0, 1, 0), Vector3(0, 1, 0), Vector3(0, 1, 0));
		polygon.polygons[2].setColors(Vector3(0, 0, 1), Vector3(0, 0, 1), Vector3(0, 0, 1));
		sceneObjects.push_back(polygon);
		selectedObject = sceneObjects.size() - 1;
	}

	void Scene::addPolygon() {
		SceneObject polygon(std::vector<Polygon> {
			Polygon(Vector3(0, 0, 0), Vector3(1, 0, 0), Vector3(0, 1, 0)),
		});
		polygon.polygons[0].setColors(Vector3(1, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1));
		sceneObjects.push_back(polygon);
		selectedObject = sceneObjects.size() - 1;
	}
}