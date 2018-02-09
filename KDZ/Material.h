#pragma once

#include "Vector3.h"
#include "Vector4.h"

namespace GL {

	// The Material class contains the information about object's lighting parameters.
	class Material {
	public:
		Material();
		Material(Vector3 _amb, Vector3 _dif, Vector3 _spec, float _shine);
		Material(const Material &mat);

		Vector3 ambient;
		Vector3 diffuse;
		Vector3 specular;
		float shininess;

	};
}
