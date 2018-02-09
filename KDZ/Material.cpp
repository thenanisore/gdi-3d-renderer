#include "Material.h"

namespace GL {

	Material::Material() : Material::Material(Vector3(1.f, 1.f, 1.f), Vector3(1.f, 1.f, 1.f), Vector3(1.f, 1.f, 1.f), 32.f) { }

	Material::Material(Vector3 _amb, Vector3 _dif, Vector3 _spec, float _shine) : ambient(_amb), diffuse(_dif), specular(_spec), shininess(_shine) { }

	Material::Material(const Material &mat) {
		ambient = mat.ambient;
		diffuse = mat.diffuse;
		specular = mat.specular;
		shininess = mat.shininess;
	}
}