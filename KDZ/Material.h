#pragma once

#include "Vector3.h"
#include "Vector4.h"

namespace GL {

	const float DEFAULT_MATERIAL_AMBIENCE = 1.f;
	const float DEFAULT_MATERIAL_DIFFUSE = 1.f;
	const float DEFAULT_MATERIAL_SPECULAR = 1.f;
	const int DEFAULT_MATERIAL_SHININESS = 32;
	const Vector4 DEFAULT_MATERIAL_COLOR = Vector4(1.f, 1.f, 1.f, 1.f);

	// The Material class contains the information about object's lighting parameters.
	class Material {
	public:
		Material();
		Material(float _amb, float _dif, float _spec, int _shine);
		Material(float _amb, float _dif, float _spec, int _shine, Vector4 _color);
		Material(const Material &mat);

		float getAmbient() const;
		float getDiffuse() const;
		float getSpecular() const;
		Vector4 getAmbientColor() const;
		Vector4 getDiffuseColor() const;
		Vector4 getSpecularColor() const;
		int getShininess() const;
		Vector4 getColor() const;

		void setAmbient(float ambient);
		void setDiffuse(float diffuse);
		void setSpecular(float specular);
		void setShininess(int shininess);
		void setColor(Vector4 color);

		void reset();

	private:
		Vector4 color;
		float ambient;
		float diffuse;
		float specular;
		int shininess;
	};
}
