#pragma once

#include "SceneObject.h"

namespace GL {

	// The Shapes.h file contains some pre-defined 3-dimensional objects.
	namespace Objects {

		enum Shape { CUBE, PYRAMID, SPHERE, TORUS, OCTAHEDRON, TETRAHEDRON };

		// Returns a SceneObject of the given shape.
		SceneObject generateObject(Shape objShape);
	}
}