#pragma once

#include "Vector3.h"

namespace GL {

	// The Light class represents a light source.
	class Light {
	public:
		Light();
		Light(Vector3 position, Vector3 color, Vector3 ambient, Vector3 diffuse, Vector3 specular);
		Light(Vector3 position);
		Light(const Light &light);

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
