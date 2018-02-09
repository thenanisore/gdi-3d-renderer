#pragma once

#include "Vector3.h"

namespace GL {

	// The Light class represents a light source.
	class Light {
	public:
		const Vector3 DEFAULT_LIGHT_COLOR = Vector3(1.f, 1.f, 1.f);

		Light();
		Light(Vector3 position, Vector3 color, Vector3 ambient, Vector3 diffuse, Vector3 specular);
		Light(Vector3 position);
		Light(const Light &light);
		// Copy assignment operator
		Light& operator=(const Light &light);

		void reset();

		Vector3 initPosition;
		Vector3 position;
		Vector3 color;
		Vector3 ambient;
		Vector3 diffuse;
		Vector3 specular;

		bool on;
		bool isPhongMode;
	};
}
