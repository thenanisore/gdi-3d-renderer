/*
* Студент: Иванов Олег Владимирович
* Группа: 141/1, 4 курс
* КДЗ #1, Вариант 1: 3D-сцена в GDI.
*
* Класс SceneObject: объект 3-мерной сцены, преобразования объекта, перевод в мировые координаты.
*/

#pragma once

#include "Polygon.h"
#include "Material.h"

#include <vector>
#include <cmath>

namespace GL {

	// The SceneObject class represents a 3D object on the scene, made up of polygons.
	class SceneObject
	{
	public:
		SceneObject();
		SceneObject(std::vector<Polygon> _polygons);
		SceneObject(const std::vector<Vector3> &vertices, std::vector<Vector3> indices);
		SceneObject(const std::vector<Vector3> &vertices, const std::vector<Vector4> &colors, std::vector<Vector3> indices);
		// Copy constructor.
		SceneObject(const SceneObject &obj);

		Vector3 getPosition() const;
		Vector3 getScale() const;
		Vector3 getRotation() const;
		Vector3 getReflection() const;

		void setPosition(const Vector3 &newPosition);
		void setScale(const Vector3 &newScale);
		void setRotation(const Vector3 &newRotation);
		void setReflection(bool xy, bool xz, bool yz);

		Material getMaterial() const;
		void setMaterialParameters(float ambience, float diffuse, float specular, int shininess);
		Vector4 getMaterialParameters();
		void setMaterialColor(const Vector4 &col);
		Vector4 getMaterialColor();
		void resetMaterial();
		
		void setTextureIndex(int iTex);
		void removeTexture();
		int getTextureIndex();

		// Sets the colors of the SceneObject's polygons. If vertices = true, then it assumes the vector defines the color in each vertex (3 per polygon).
		void setPolygonColors(const std::vector<Vector4> &cols, bool vertices = false);

		Matrix4 getModelMatrix() const;
		void reset();

		// Adds a polygon to the SceneObject's mesh.
		void addPolygon(Polygon pol);
		std::vector<Polygon> polygons;

	private:
		// Object's coordinates (in the world space).
		Vector3 position;
		// Scale multiplier (in the world space).
		Vector3 scale;
		// Rotation angles (in the world space).
		Vector3 rotation;
		// Color.
		Material material;

		// reflection flags:
		bool reflectionXY;
		bool reflectionXZ;
		bool reflectionYZ;

		// the number of the currently used texture (-1 if no texture)
		int textureIndex;
	};
}
