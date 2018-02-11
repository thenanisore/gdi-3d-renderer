/*
* Студент: Иванов Олег Владимирович
* Группа: 141/1, 4 курс
* КДЗ #1, Вариант 1: 3D-сцена в GDI.
*
* Класс SceneObject: объект 3-мерной сцены, преобразования объекта, перевод в мировые координаты.
*/

#include "SceneObject.h"
#include "Util.h"

namespace GL {

	SceneObject::SceneObject() : SceneObject::SceneObject(std::vector<Polygon>()) { }

	SceneObject::SceneObject(std::vector<Polygon> _polygons)
		: polygons(_polygons), position(), scale(1.0f, 1.0f, 1.0f), rotation(), 
		  reflectionXY(false), reflectionXZ(false), reflectionYZ(false), material(), textureIndex(-1) { }

	SceneObject::SceneObject(const std::vector<Vector3> &vertices, std::vector<Vector3> indices)
	    : SceneObject::SceneObject() 
	{
		for (int i = 0; i < indices.size(); i++) {
			addPolygon(GL::Polygon(
				vertices[(int)indices[i].x],
				vertices[(int)indices[i].y],
				vertices[(int)indices[i].z]
			));
		}
	}

	SceneObject::SceneObject(const std::vector<Vector3> &vertices, const std::vector<Vector4> &colors, std::vector<Vector3> indices) 
		: SceneObject::SceneObject()
	{
		if (colors.size() != vertices.size()) {
			throw new std::invalid_argument("Colors must be specified for each vertex");
		}
		for (int i = 0; i < indices.size(); i++) {
			addPolygon(GL::Polygon(
				vertices[(int)indices[i].x],
				vertices[(int)indices[i].y],
				vertices[(int)indices[i].z]
			));
			polygons[polygons.size() - 1].setColors(
				colors[(int)indices[i].x],
				colors[(int)indices[i].y],
				colors[(int)indices[i].z]
			);
		}
	}

	SceneObject::SceneObject(const std::vector<Vector3>& vertices, const std::vector<Vector4>& colors, std::vector<Vector3> texCoords, std::vector<Vector3> indices)
		: SceneObject::SceneObject()
	{
		if (colors.size() != vertices.size()) {
			throw new std::invalid_argument("Colors must be specified for each vertex");
		}
		if (texCoords.size() != indices.size() * 3) {
			throw new std::invalid_argument("Texture coordinates must be specified for each polygon");
		}
		for (int i = 0; i < indices.size(); i++) {
			addPolygon(GL::Polygon(
				vertices[(int)indices[i].x],
				vertices[(int)indices[i].y],
				vertices[(int)indices[i].z]
			));
			polygons[polygons.size() - 1].setColors(
				colors[(int)indices[i].x],
				colors[(int)indices[i].y],
				colors[(int)indices[i].z]
			);
			polygons[polygons.size() - 1].setTexCoords(
				texCoords[3 * i],
				texCoords[3 * i + 1],
				texCoords[3 * i + 2]
			);
		}
	}

	SceneObject::SceneObject(const SceneObject & obj) {
		position = obj.getPosition();
		rotation = obj.getRotation();
		scale = obj.getScale();
		Vector3 refl = obj.getReflection();
		reflectionXY = refl.z;
		reflectionXZ = refl.y;
		reflectionYZ = refl.x;
		material = obj.getMaterial();
		polygons = obj.polygons;
		textureIndex = obj.textureIndex;
	}

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

	Material SceneObject::getMaterial() const {
		return material;
	}

	void SceneObject::setMaterialParameters(float ambience, float diffuse, float specular, int shininess) {
		material.setAmbient(ambience);
		material.setDiffuse(diffuse);
		material.setSpecular(specular);
		material.setShininess(shininess);
	}

	Vector4 SceneObject::getMaterialParameters() {
		return Vector4(material.getAmbient(), material.getDiffuse(), material.getSpecular(), material.getShininess());
	}

	void SceneObject::setMaterialColor(const Vector4 &col) {
		material.setColor(col);
	}

	Vector4 SceneObject::getMaterialColor() {
		return material.getColor();
	}

	void SceneObject::resetMaterial() {
		material.reset();
	}

	void SceneObject::setTextureIndex(int iTex) {
		textureIndex = iTex;
	}

	void SceneObject::removeTexture() {
		textureIndex = -1;
	}

	int SceneObject::getTextureIndex() const {
		return textureIndex;
	}

	// Sets the colors of the SceneObject's polygons. If vertices = true, then it assumes the vector defines the color in each vertex (3 per polygon).
	void SceneObject::setPolygonColors(const std::vector<Vector4> &cols, bool vertices) {
		for (int i = 0; i < polygons.size(); i++) {
			if (vertices) {
				// color per vertex
				if (cols.size() != polygons.size() * 3) {
					throw new std::invalid_argument("The color should be specified for each vertex.");
				}
				polygons[i].setColors(cols[3 * i], cols[3 * i + 1], cols[3 * i + 2]);
			}
			else {
				// color per polygon
				if (cols.size() != polygons.size()) {
					throw new std::invalid_argument("The color should be specified for each polygon.");
				}
				polygons[i].setColor(cols[i]);
			}
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