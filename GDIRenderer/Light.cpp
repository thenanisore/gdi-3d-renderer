/*
* Copyright © 2018 Oleg Ivanov
* Licensed under the MIT license.
*/

#include "Light.h"
#include "Util.h"

namespace GL {

	Light::Light() : Light(Vector3()) { }

	Light::Light(Vector3 _pos, Vector3 _col, float _amb, float _diff, float _spec) 
		: position(_pos), initPosition(_pos), color(_col), on(true), mode(DEFAULT_LIGHT_MODE) {
		setAmbient(_amb);
		setDiffuse(_diff);
		setSpecular(_spec);
	}

	Light::Light(Vector3 _pos) : position(_pos), initPosition(_pos), color(DEFAULT_LIGHT_COLOR),
		ambient(DEFAULT_LIGHT_AMBIENCE), diffuse(DEFAULT_LIGHT_DIFFUSE), specular(DEFAULT_LIGHT_SPECULAR), 
		on(true), mode(DEFAULT_LIGHT_MODE) { }

	Light::Light(const Light &light) {
		on = light.on;
		mode = light.mode;
		initPosition = light.initPosition;
		position = light.position;
		color = light.color;
		ambient = light.getAmbient();
		diffuse = light.getDiffuse();
		specular = light.getSpecular();
	}

	Light & Light::operator=(const Light & light) {
		on = light.on;
		mode = light.mode;
		initPosition = light.initPosition;
		position = light.position;
		color = light.color;
		ambient = light.getAmbient();
		diffuse = light.getDiffuse();
		specular = light.getSpecular();
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

	Vector4 Light::getAmbientColor() const {
		return color * ambient;
	}

	Vector4 Light::getDiffuseColor() const {
		return color * diffuse;
	}

	Vector4 Light::getSpecularColor() const {
		return color * specular;
	}

	void Light::setAmbient(float _amb) {
		ambient = Util::clamp(_amb, 0.f, 1.f);
	}

	void Light::setDiffuse(float _diff) {
		diffuse = Util::clamp(_diff, 0.f, 1.f);
	}

	void Light::setSpecular(float _spec) {
		specular = Util::clamp(_spec, 0.f, 1.f);
	}

	void Light::reset() {
		on = true;
		position = initPosition;
		mode = DEFAULT_LIGHT_MODE;
		color = DEFAULT_LIGHT_COLOR;
		ambient = DEFAULT_LIGHT_AMBIENCE;
		diffuse = DEFAULT_LIGHT_DIFFUSE;
		specular = DEFAULT_LIGHT_SPECULAR;
	}
}