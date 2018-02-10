#pragma once

#include "Vector3.h"

namespace GL {

	enum LightMode { FLAT, PHONG, GOURAUD };

	// The Light class represents a light source.
	class Light {
	public:
		const Vector3 DEFAULT_LIGHT_COLOR = Vector3(1.f, 1.f, 1.f);

		Light();
		Light(Vector3 _pos, Vector3 _col, float _amb, float _dif, float _spec);
		Light(Vector3 position);
		Light(const Light &light);
		// Copy assignment operator
		Light& operator=(const Light &light);

		float getAmbient() const;
		float getDiffuse() const;
		float getSpecular() const;
		void setAmbient(float ambient);
		void setDiffuse(float diffuse);
		void setSpecular(float specular);

		void reset();

		Vector3 initPosition;
		Vector3 position;
		Vector3 color;

		bool on;
		LightMode mode;

	private:
		float ambient;
		float diffuse;
		float specular;
	};
}
