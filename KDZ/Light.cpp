#include "Light.h"

namespace GL {

	Light::Light() : Light(Vector3()) { }

	Light::Light(Vector3 _pos, Vector3 _col, float _amb, float _diff, float _spec) 
		: position(_pos), initPosition(_pos), color(_col), ambient(_amb), diffuse(_diff), 
		  specular(_spec), on(true), mode(LightMode::PHONG) {
		setAmbient(_amb);
		setDiffuse(_diff);
		setSpecular(_spec);
	}

	Light::Light(Vector3 _pos) : position(_pos), initPosition(_pos), color(DEFAULT_LIGHT_COLOR),
		ambient(0.1f), diffuse(0.5f), specular(1.f), on(true), mode(LightMode::PHONG) { }

	Light::Light(const Light &light) {
		on = light.on;
		mode = LightMode::PHONG;
		initPosition = light.initPosition;
		position = light.position;
		color = light.color;
		ambient = light.ambient;
		diffuse = light.diffuse;
		specular = light.specular;
	}

	Light & Light::operator=(const Light & light) {
		on = light.on;
		mode = light.mode;
		initPosition = light.initPosition;
		position = light.position;
		color = light.color;
		ambient = light.ambient;
		diffuse = light.diffuse;
		specular = light.specular;
		return *this;
	}

	float Light::getAmbient() const {
		return ambient;
	}

	float Light::getDiffuse() const {
		return diffuse;
	}

	float Light::getSpecular() const {
		return specular;
	}

	void Light::setAmbient(float _amb) {
		if (_amb < 0) ambient = 0.f;
		else if (_amb > 1) ambient = 1.f;
		else ambient = _amb;
	}

	void Light::setDiffuse(float _diff) {
		if (_diff < 0) diffuse = 0.f;
		else if (_diff > 1) diffuse = 1.f;
		else diffuse = _diff;
	}

	void Light::setSpecular(float _spec) {
		if (_spec < 0) specular = 0.f;
		else if (_spec > 1) specular = 1.f;
		else specular = _spec;
	}

	void Light::reset() {
		on = true;
		mode = LightMode::PHONG;
		position = initPosition;
		color = DEFAULT_LIGHT_COLOR;
		ambient = 0.1f;
		diffuse = 0.5f;
		specular = 1.f;
	}
}