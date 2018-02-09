#pragma once

#include "Vector3.h"
#include "Vector4.h"

namespace GL {

	// The Material class contains the information about object's lighting parameters.
	class Material {
		Material();
		Material(Vector3 _amb, Vector3 _dif, Vector3 _spec, float _shine);
		Material(const Material &mat);

		Vector3 ambient;
		Vector3 diffuse;
		Vector3 specular;
		float shininess;

	};

	Material::Material() : Material::Material(Vector3(1.f, 1.f, 1.f), Vector3(1.f, 1.f, 1.f), Vector3(1.f, 1.f, 1.f), 32.f) { }

	Material::Material(Vector3 _amb, Vector3 _dif, Vector3 _spec, float _shine) : ambient(_amb), diffuse(_dif), specular(_spec), shininess(_shine) { }

	Material::Material(const Material &mat) {
		ambient = mat.ambient;
		diffuse = mat.diffuse;
		specular = mat.specular;
		shininess = mat.shininess;
	}
}
