#include "Material.h"

namespace GL {

	Material::Material() : Material::Material(1.f, 1.f, 1.f, 32.f) { }

	Material::Material(float _amb, float _dif, float _spec, float _shine) : ambient(_amb), diffuse(_dif), specular(_spec), shininess(_shine), color(Vector3(1.f, 1.f, 1.f)) { }

	Material::Material(float _amb, float _dif, float _spec, float _shine, Vector3 _color) : ambient(_amb), diffuse(_dif), specular(_spec), shininess(_shine), color(_color) { }

	Material::Material(const Material &mat) {
		color = mat.color;
		ambient = mat.ambient;
		diffuse = mat.diffuse;
		specular = mat.specular;
		shininess = mat.shininess;
	}

	float Material::getAmbient() const {
		return ambient;
	}

	float Material::getDiffuse() const {
		return diffuse;
	}

	float Material::getSpecular() const {
		return specular;
	}

	void Material::setAmbient(float _amb) {
		if (_amb < 0) ambient = 0.f;
		else if (_amb > 1) ambient = 1.f;
		else ambient = _amb;
	}
	
	void Material::setDiffuse(float _diff) {
		if (_diff < 0) diffuse = 0.f;
		else if (_diff > 1) diffuse = 1.f;
		else diffuse = _diff;
	}

	void Material::setSpecular(float _spec) {
		if (_spec < 0) specular = 0.f;
		else if (_spec > 1) specular = 1.f;
		else specular = _spec;
	}
}