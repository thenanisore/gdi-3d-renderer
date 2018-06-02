/*
* Copyright © 2018 Oleg Ivanov
* Licensed under the MIT license.
*/

#include "Material.h"
#include "Util.h"

namespace GL {

	Material::Material() : Material::Material(DEFAULT_MATERIAL_AMBIENCE, DEFAULT_MATERIAL_DIFFUSE, DEFAULT_MATERIAL_SPECULAR, DEFAULT_MATERIAL_SHININESS) { }

	Material::Material(float _amb, float _dif, float _spec, int _shine) 
		: ambient(_amb), diffuse(_dif), specular(_spec), shininess(_shine), color(DEFAULT_MATERIAL_COLOR) { }

	Material::Material(float _amb, float _dif, float _spec, int _shine, Vector4 _color) 
		: ambient(_amb), diffuse(_dif), specular(_spec), shininess(_shine), color(_color) { }

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

	Vector4 Material::getAmbientColor() const {
		return color * ambient;
	}

	Vector4 Material::getDiffuseColor() const {
		return color * diffuse;
	}

	Vector4 Material::getSpecularColor() const {
		return color * specular;
	}

	int Material::getShininess() const {
		return shininess;
	}

	Vector4 Material::getColor() const {
		return color;
	}

	void Material::setAmbient(float _amb) {
		ambient = Util::clamp(_amb, 0.f, 1.f);
	}
	
	void Material::setDiffuse(float _diff) {
		diffuse = Util::clamp(_diff, 0.f, 1.f);
	}

	void Material::setSpecular(float _spec) {
		specular = Util::clamp(_spec, 0.f, 1.f);
	}

	void Material::setShininess(int _shine) {
		shininess = Util::clamp(_shine, 2, 256);
	}

	void Material::setColor(Vector4 _col) {
		color = Util::clampVec(_col, 0.f, 255.f);
	}

	void Material::reset() {
		color = DEFAULT_MATERIAL_COLOR;
		ambient = DEFAULT_MATERIAL_AMBIENCE;
		diffuse = DEFAULT_MATERIAL_DIFFUSE;
		specular = DEFAULT_MATERIAL_SPECULAR;
		shininess = DEFAULT_MATERIAL_SHININESS;
	}
}