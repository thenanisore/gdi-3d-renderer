#include "Scene.h"
#include "Util.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	const float positionMultiplier = 0.1f;
	const float rotationMultiplier = 1.0f;
	const float scaleMultiplier = 0.1f;
	const float cameraPositionMultiplier = 0.1f;
	const float camerRotationMultiplier = 1.0f;
	const float lightPositionMultiplier = 0.1f;
	const float lightAmbientMultiplier = 0.01f;
	const float lightDiffuseMultiplier = 0.01f;
	const float lightSpecularMultiplier = 0.01f;
	const float materialAmbientMultiplier = 0.01f;
	const float materialDiffuseMultiplier = 0.01f;
	const float materialSpecularMultiplier = 0.01f;

	Scene::Scene() : camera(), selectedObject(0) {
		lightSource = Light(camera.getPosition());
		faceCull = true;
		perspective = true;
		drawWireframe = false;
		drawSolid = true;
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
				renderer->renderObject(object, model, view, projection, lightSource, drawWireframe, drawSolid);
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

	void Scene::resetObject() {
		if (!isEmpty()) {
			sceneObjects[selectedObject].reset();
		}
	}

	void Scene::addObject(SceneObject obj) {
		sceneObjects.push_back(obj);
		// select the added object
		selectedObject = sceneObjects.size() - 1;
	}

	void Scene::deleteObject() {
		if (!isEmpty()) {
			sceneObjects.erase(sceneObjects.begin() + selectedObject);
			if (selectedObject > 0) {
				selectedObject--;
			}
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

	Vector3 Scene::getCameraPosition(bool worldCoords) const {
		return camera.getPosition() / (worldCoords ? 1.f : cameraPositionMultiplier);
	}

	Vector3 Scene::getCameraRotation(bool worldCoords) const {
		return camera.getRotation() / (worldCoords ? 1.f : camerRotationMultiplier);
	}

	void Scene::resetCamera() {
		camera.reset();
	}

	// methods to manipulate the light source:

	Vector3 Scene::getLightPosition(bool worldCoords) {
		return lightSource.position / (worldCoords ? 1.f : lightPositionMultiplier);
	}

	void Scene::setLightPosition(int x_coord, int y_coord, int z_coord) {
		lightSource.position = Vector3(x_coord, y_coord, z_coord);
	}

	Color Scene::getLightColor() {
		return Util::vecToColor(lightSource.color);
	}

	bool Scene::isLightOn() {
		return lightSource.on;
	}

	LightMode Scene::getLightMode() {
		return lightSource.mode;
	}

	void Scene::setLightColor(Color^ lightColor) {
		lightSource.color = Util::colorToVec(lightColor).toVec3();
	}

	void Scene::setLightOn(bool isOn) {
		lightSource.on = isOn;
	}

	void Scene::setLightMode(LightMode _mode) {
		lightSource.mode = _mode;
	}

	void Scene::setLightParams(float _amb, float _diff, float _spec) {
		lightSource.setAmbient(_amb * lightAmbientMultiplier);
		lightSource.setDiffuse(_diff * lightDiffuseMultiplier);
		lightSource.setSpecular(_spec * lightSpecularMultiplier);
	}

	Vector3 Scene::getLightParams() {
		float amb = lightSource.getAmbient() / lightAmbientMultiplier;
		float diff = lightSource.getDiffuse() / lightDiffuseMultiplier;
		float spec = lightSource.getSpecular() / lightSpecularMultiplier;
		return Vector3(amb, diff, spec);
	}

	void Scene::resetLighting() {
		lightSource.reset();
	}

	// methods to manipulate the current object's material:

	void Scene::setMaterialParams(int _ambi, int _diff, int _spec, int _shine) {
		if (!isEmpty()) {
			sceneObjects[selectedObject].setMaterialParameters(
				_ambi * materialAmbientMultiplier,
				_diff * materialDiffuseMultiplier,
				_spec * materialSpecularMultiplier,
				pow(2.f, _shine)
			);
		}
	}

	void Scene::setMaterialColor(Color ^col) {
		if (!isEmpty()) {
			sceneObjects[selectedObject].setMaterialColor(Util::colorToVec(col));
		}
	}

	Vector4 Scene::getMaterialParams() {
		if (!isEmpty()) {
			Vector4 params = sceneObjects[selectedObject].getMaterialParameters();
			float amb = params.x / materialAmbientMultiplier;
			float diff = params.y / materialDiffuseMultiplier;
			float spec = params.z / materialSpecularMultiplier;
			float shine = (int)log2(params.w);
			return Vector4(amb, diff, spec, shine);
		}
	}

	Color Scene::getMaterialColor() {
		if (!isEmpty()) {
			return Util::vecToColor(sceneObjects[selectedObject].getMaterialColor());
		}
	}

	void Scene::resetMaterial() {
		if (!isEmpty()) {
			sceneObjects[selectedObject].resetMaterial();
		}
	}

	// other methods:

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
		std::vector<Vector4> colors;
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
					colors.push_back(Vector4(data, 1.f));
					break;
				case 'f':
					// polygon indices
					data = Util::parseVec3(trimmed->Substring(2));
					indices.push_back(data - 1);
					break;
				default:
					// do nothing?
					continue;
				}
			}
		}
		// construct a SceneObject
		SceneObject newObj(vertices, colors, indices);
		addObject(newObj);

		return true;
	}
}