#pragma once

#include "Vector3.h"

namespace GL {

	// The Light class represents a light source.
	class Light {
		Light();
		Light(Vector3 position, Vector3 color, Vector3 ambient, Vector3 diffuse, Vector3 specular);
		Light(const Light &light);

		Vector3 position;
		Vector3 color;
		Vector3 ambient;
		Vector3 diffuse;
		Vector3 specular;
	};

	Light::Light() : position(), color(1.f, 1.f, 1.f), ambient(0.1f, 0.1f, 0.1f),
		diffuse(0.5f, 0.5f, 0.5f), specular(1.f, 1.f, 1.f) { }

	Light::Light(Vector3 _pos, Vector3 _col, Vector3 _amb, Vector3 _dif, Vector3 _spec) 
		: position(_pos), color(_col), ambient(_amb), diffuse(_dif), specular(_spec) { }

	Light::Light(const Light &light) {
		position = light.position;
		color = light.color;
		ambient = light.ambient;
		diffuse = light.diffuse;
		specular = light.specular;
	}
}
