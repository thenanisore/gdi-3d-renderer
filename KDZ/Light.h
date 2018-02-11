/*
 * Студент: Иванов Олег Владимирович
 * Группа: 141/1, 4 курс
 * КДЗ #1, Вариант 1: 3D-сцена в GDI.
 * 
 * Класс Light: источник света.
 */

#pragma once

#include "Vector3.h"
#include "Vector4.h"

namespace GL {

	enum LightMode { FLAT, PHONG, GOURAUD };

	const Vector3 DEFAULT_LIGHT_COLOR = Vector3(1.f, 1.f, 1.f);
	const float DEFAULT_LIGHT_AMBIENCE = 0.1f;
	const float DEFAULT_LIGHT_DIFFUSE = 0.5f;
	const float DEFAULT_LIGHT_SPECULAR = 0.5f;
	const LightMode DEFAULT_LIGHT_MODE = LightMode::PHONG;

	// The Light class represents a light source with a position, color and intensity parameters.
	class Light {
	public:
		Light();
		Light(Vector3 _pos, Vector3 _col, float _amb, float _dif, float _spec);
		Light(Vector3 position);
		Light(const Light &light);
		// Copy assignment operator
		Light& operator=(const Light &light);

		// Returns the ambient light intensity of the light source.
		float getAmbient() const;
		// Returns the diffused light intensity of the light source.
		float getDiffuse() const;
		// Returns the specular light intensity of the light source.
		float getSpecular() const;
		// Returns the color of the ambient light of the light source.
		Vector4 getAmbientColor() const;
		// Returns the color of the diffused light of the light source.
		Vector4 getDiffuseColor() const;
		// Returns the color of the specular light of the light source.
		Vector4 getSpecularColor() const;
		// Sets the ambient light intensity of the light source.
		void setAmbient(float ambient);
		// Sets the ambient light intensity of the light source.
		void setDiffuse(float diffuse);
		// Sets the ambient light intensity of the light source.
		void setSpecular(float specular);

		// Sets the parameters of the light source to the default ones.
		void reset();

		// The initial position of the light source (is set at the construction).
		Vector3 initPosition;
		// The position of the light source.
		Vector3 position;
		// The color of the light source.
		Vector4 color;

		bool on;
		LightMode mode;

	private:
		float ambient;
		float diffuse;
		float specular;
	};
}
