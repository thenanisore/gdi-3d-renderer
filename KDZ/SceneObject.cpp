#include "SceneObject.h"
#include "Util.h"

namespace GL {

	SceneObject::SceneObject() : SceneObject::SceneObject(std::vector<Polygon>()) { }

	SceneObject::SceneObject(std::vector<Polygon> _polygons)
		: polygons(_polygons), position(), scale(1.0f, 1.0f, 1.0f), rotation(), 
		  reflectionXY(false), reflectionXZ(false), reflectionYZ(false) { }

	Vector3 SceneObject::getPosition() const {
		return Vector3(position);
	}

	Vector3 SceneObject::getScale() const {
		return Vector3(scale);
	}

	Vector3 SceneObject::getRotation() const {
		return Vector3(rotation);
	}
	
	Vector3 SceneObject::getReflection() const {
		return Vector3(reflectionYZ, reflectionXZ, reflectionXY);
	}

	void SceneObject::setPosition(const Vector3 &newPosition) {
		position = newPosition;
	}

	void SceneObject::setScale(const Vector3 &newScale) {
		scale = newScale;
	}

	void SceneObject::setRotation(const Vector3 &newRotation) {
		rotation = newRotation;
	}

	void SceneObject::setReflection(bool xy, bool xz, bool yz) {
		reflectionXY = xy;
		reflectionXZ = xz;
		reflectionYZ = yz;
	}

	void SceneObject::setPolygonColor(const std::vector<Vector4> cols) {
		for (int i = 0; i < cols.size(); i++) {
			polygons[i].setColor(cols[i]);
		}
	}

	Matrix4 SceneObject::getModelMatrix() const {
		Matrix4 model;
		// multiplication order: T * R * S * identity
		model = Util::scale(model, scale);
		model = Util::rotateX(model, rotation.x);
		model = Util::rotateY(model, rotation.y);
		model = Util::rotateZ(model, rotation.z);
		model = Util::translate(model, position);
		// apply reflection
		if (reflectionXY) model = Util::reflectXY(model);
		if (reflectionXZ) model = Util::reflectXZ(model);
		if (reflectionYZ) model = Util::reflectYZ(model);

		return model;
	}

	void SceneObject::reset() {
		setPosition(Vector3());
		setScale(Vector3(1.0f, 1.0f, 1.0f));
		setRotation(Vector3());
		setReflection(false, false, false);
	}

	void SceneObject::addPolygon(Polygon pol) {
		polygons.push_back(pol);
	}
}