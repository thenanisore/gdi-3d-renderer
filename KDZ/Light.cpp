#include "Light.h"

namespace GL {

	Light::Light() : Light(Vector3()) { }

	Light::Light(Vector3 _pos, Vector3 _col, Vector3 _amb, Vector3 _dif, Vector3 _spec) 
		: position(_pos), initPosition(_pos), color(_col), ambient(_amb), diffuse(_dif), 
		  specular(_spec), on(true), isPhongMode(true) { }

	Light::Light(Vector3 _pos) : position(_pos), initPosition(_pos), color(1.f, 1.f, 1.f),
		ambient(0.1f, 0.1f, 0.1f), diffuse(0.5f, 0.5f, 0.5f), specular(1.f, 1.f, 1.f), on(true), isPhongMode(true) { }

	Light::Light(const Light &light) {
		on = light.on;
		isPhongMode = light.isPhongMode;
		initPosition = light.initPosition;
		position = light.position;
		color = light.color;
		ambient = light.ambient;
		diffuse = light.diffuse;
		specular = light.specular;
	}

	void Light::reset() {
		on = isPhongMode = true;
		position = initPosition;
		color = Vector3(1.f, 1.f, 1.f);
		ambient = Vector3(0.1f, 0.1f, 0.1f);
		diffuse = Vector3(0.5f, 0.5f, 0.5f);
		specular = Vector3(1.f, 1.f, 1.f);
	}
}