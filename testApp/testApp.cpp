#include "Stdafx.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Camera.h"
#include "Scene.h"
#include "SceneObject.h"

#include <iostream>

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

void test1() {
	GL::Matrix4 trans(std::vector<float> { 1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 1, 3, 0, 0, 0, 1 });
	GL::Matrix4 scale(std::vector<float> { 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1 });
	GL::Vector4 v1;
	GL::Vector4 v2(5, -3, 1, 1);

	print(trans);
	print(scale);
	print(v1);
	print(v2);

	print("\nmult:");
	print(trans * scale);
	print("v1:");
	print(trans * v1);
	print(scale * v1);
	print("v2:");
	print(trans * v2);
	print(scale * v2);

	GL::Polygon p1(std::vector<GL::Vector3> {
		GL::Vector3(-1, 0, 1),
		GL::Vector3(0, 0, -1),
		GL::Vector3(1, 0, 1)
	});
	GL::Polygon p2(std::vector<GL::Vector3> {
		GL::Vector3(0, 0, -1),
		GL::Vector3(-1, 0, 1),
		GL::Vector3(2, 1.25, 1)
	});

	// scene object
	GL::SceneObject t(std::vector<GL::Polygon> { p1, p2 });
	
	print(t);

	t.scale(GL::Vector3(3, -1, 1));

	print(t);

	t.reflectXY();

	print(t);

	t.translate(GL::Vector3(10, 10, -10));

	print(t);
}

int main(array<System::String ^> ^args)
{
	GL::Camera cam(GL::Vector3(0, 0, 3), GL::Vector3(0, 0, 0), GL::Vector3(0, 1, 0));
	print(cam.getLookAt());

	GL::Camera cam1(GL::Vector3(0, 0, 3), GL::Vector3(0, 0, 0), GL::Vector3(0, -1, 0));
	print(cam1.getLookAt());

	std::getchar();
    return 0;
}
