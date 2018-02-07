#include "Stdafx.h"
#include "Matrix.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Camera.h"
#include "Scene.h"
#include "SceneObject.h"

#include <iostream>
#include <vector>

using namespace System;

// methods for debug purposes

void print(const GL::Matrix3 &m) {
	for (int i = 0; i < m.dim; i++) {
		if (i == 0) std::cout << "{ "; 
		else std::cout << std::endl << "  ";
		for (int j = 0; j < m.dim; j++) {
			std::cout << m.get(i, j) << " ";
		}
	}
	std::cout << "}" << std::endl;
}

void print(const GL::Matrix4 &m) {
	for (int i = 0; i < m.dim; i++) {
		if (i == 0) std::cout << "{ "; 
		else std::cout << std::endl << "  ";
		for (int j = 0; j < m.dim; j++) {
			std::cout << m.get(i, j) << " ";
		}
	}
	std::cout << "}" << std::endl;
}

void print(const GL::Vector3 &v) {
	std::cout << "(" << v.x << "; " << v.y << "; " << v.z << ")" << std::endl;
}

void print(const GL::Vector4 &v) {
	std::cout << "(" << v.x << "; " << v.y << "; " << v.z << "; " << v.w <<  ")" << std::endl;
}

void print(const GL::Polygon &p) {
	std::cout << "Poly:" << std::endl;
	for (const GL::Vector4 &vert : p.vertices) {
		print(vert);
	}
}

void print(const GL::Polygon &p, GL::Matrix4 tr) {
	std::cout << "Poly:" << std::endl;
	for (const GL::Vector4 &vert : p.vertices) {
		print(tr * vert);
	}
}

void printh(const GL::Polygon &p, GL::Matrix4 tr) {
	std::cout << "Norm Poly:" << std::endl;
	for (const GL::Vector4 &vert : p.vertices) {
		print((tr * vert).fromHomogeneous());
	}
}

void print(char* str) {
	std::cout << str << std::endl;
}

void print(GL::SceneObject so) {
	std::cout << "--- SceneObject ---" << std::endl;
	for (const GL::Polygon &pol : so.polygons) {
		print(pol);
	}
	std::cout << std::endl;
}

void print(GL::SceneObject so, GL::Matrix4 tr) {
	std::cout << "--- SceneObject ---" << std::endl;
	for (const GL::Polygon &pol : so.polygons) {
		print(pol, tr);
	}
	std::cout << std::endl;
}

void printh(GL::SceneObject so, GL::Matrix4 tr) {
	std::cout << "--- SceneObject ---" << std::endl;
	for (const GL::Polygon &pol : so.polygons) {
		printh(pol, tr);
	}
	std::cout << std::endl;
}

void test3() {
	GL::SceneObject obj(std::vector<GL::Polygon> {
		// center
		GL::Polygon(GL::Vector3(0, 0, 0.0), GL::Vector3(1, 0, 0.0), GL::Vector3(0, 1, 0.0)),
			// far
			GL::Polygon(GL::Vector3(0, 0, 0.2), GL::Vector3(1, 0, 0.3), GL::Vector3(0, 1, 0.3)),
			GL::Polygon(GL::Vector3(0, 0, 50), GL::Vector3(1, 0, 50), GL::Vector3(0, 1, 50)),
			GL::Polygon(GL::Vector3(0, 0, 100), GL::Vector3(1, 0, 100), GL::Vector3(0, 1, 100)),
			GL::Polygon(GL::Vector3(0, 0, 150), GL::Vector3(1, 0, 150), GL::Vector3(0, 1, 150)),
			// near (shouldn't be rendered)
			GL::Polygon(GL::Vector3(0, 0, -0.1), GL::Vector3(1, 0, -0.1), GL::Vector3(0, 1, -0.1)),
			GL::Polygon(GL::Vector3(0, 0, -0.2), GL::Vector3(1, 0, -0.2), GL::Vector3(0, 1, -0.2)),
			GL::Polygon(GL::Vector3(0, 0, -1), GL::Vector3(1, 0, -1), GL::Vector3(0, 1, -1)),
			GL::Polygon(GL::Vector3(0, 0, -2), GL::Vector3(1, 0, -2), GL::Vector3(0, 1, -2)),
			GL::Polygon(GL::Vector3(0, 0, -3), GL::Vector3(1, 0, -3), GL::Vector3(0, 1, -3)),
			GL::Polygon(GL::Vector3(0, 0, -50), GL::Vector3(1, 0, -50), GL::Vector3(0, 1, -50)),
		GL::Polygon(GL::Vector3(0, 0, -100), GL::Vector3(1, 0, -100), GL::Vector3(0, 1, -100))
	});
	print(obj);
	GL::Camera cam(GL::Vector3(0.0, 0.0, 0.0), GL::Vector3(0, 1, 0));
	GL::Matrix4 view = cam.getViewMatrix();
	GL::Camera cam2(GL::Vector3(0.0, 0.0, 10.0), GL::Vector3(0, 1, 0));
	GL::Matrix4 view2 = cam2.getViewMatrix();

	print("model");
	print(obj.getModelMatrix());
	print("view");
	print(view);
	print("view2");
	print(view2);
	GL::Matrix4 persp = GL::Util::perspective(45.0f, 800.0f/600.0f, 0.1f, 100.0f);
	//persp.set(2, 3, -0.2);
	//persp.set(3, 2, -1);
	//persp.set(2, 2, -1);
	GL::Matrix4 ortho = GL::Util::orthographic(5, 5, 0.1, 100);
	print("persp");
	print(persp);
	print("ortho");
	print(ortho);

	print("all");
	print(view * obj.getModelMatrix());
	print(persp * view * obj.getModelMatrix());
	print("all2");
	print(view * obj.getModelMatrix());
	print(persp * view2 * obj.getModelMatrix());

	print("\nafter all transf");
	print(obj, persp * view * obj.getModelMatrix());
	print("div");
	printh(obj, persp * view * obj.getModelMatrix());
	print("\nafter all transf2");
	print(obj, persp * view2 * obj.getModelMatrix());
	print("div2");
	printh(obj, persp * view2 * obj.getModelMatrix());
	print("\nafter all transf2 (transposed)");
	print(obj, persp.transposed() * view2 * obj.getModelMatrix());
	print("div2 (transposed)");
	printh(obj, persp.transposed() * view2 * obj.getModelMatrix());
}

int main(array<System::String ^> ^args) {
	GL::Vector3 a(0, 0, 0);
	GL::Vector3 b(1, 0, 0);
	GL::Vector3 c(0, 1, 0);

	std::getchar();
    return 0;
}
