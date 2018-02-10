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

	// The Light class represents a light source.
	class Light {
	public:
		Light();
		Light(Vector3 _pos, Vector3 _col, float _amb, float _dif, float _spec);
		Light(Vector3 position);
		Light(const Light &light);
		// Copy assignment operator
		Light& operator=(const Light &light);

		float getAmbient() const;
		float getDiffuse() const;
		float getSpecular() const;
		Vector4 getAmbientColor() const;
		Vector4 getDiffuseColor() const;
		Vector4 getSpecularColor() const;
		void setAmbient(float ambient);
		void setDiffuse(float diffuse);
		void setSpecular(float specular);

		void reset();

		Vector3 initPosition;
		Vector3 position;
		Vector4 color;

		bool on;
		LightMode mode;

	private:
		float ambient;
		float diffuse;
		float specular;
	};
}
