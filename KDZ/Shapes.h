/*
* Студент: Иванов Олег Владимирович
* Группа: 141/1, 4 курс
* КДЗ #1, Вариант 1: 3D-сцена в GDI.
*
* Namespace Objects: заранее заданные 3-мерные объекты (куб, сфера, тор и др.).
*/

#pragma once

#include "SceneObject.h"

namespace GL {

	// The Shapes.h file contains some pre-defined 3-dimensional objects.
	namespace Objects {
		const float DEFAULT_RADIUS = 2.f; 
		const int DEFAULT_PRECISION_LEVEL = 3;

		enum Shape { CUBE, PYRAMID, SPHERE, TORUS, OCTAHEDRON, TETRAHEDRON };

		// Returns a SceneObject of the given shape.
		SceneObject generateObject(Shape objShape, int precision = DEFAULT_PRECISION_LEVEL);
	}
}