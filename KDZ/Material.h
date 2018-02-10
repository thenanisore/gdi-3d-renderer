#pragma once

#include "Vector3.h"
#include "Vector4.h"

namespace GL {

	// The Material class contains the information about object's lighting parameters.
	class Material {
	public:
		Material();
		Material(float _amb, float _dif, float _spec, float _shine);
		Material(float _amb, float _dif, float _spec, float _shine, Vector3 _color);
		Material(const Material &mat);

		float getAmbient() const;
		float getDiffuse() const;
		float getSpecular() const;
		void setAmbient(float ambient);
		void setDiffuse(float diffuse);
		void setSpecular(float specular);

		Vector3 color;
		float ambient;
		float diffuse;
		float specular;
		float shininess;
	};
}
