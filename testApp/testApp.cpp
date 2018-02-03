// testApp.cpp : main project file.

#include "stdafx.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "Vector4.h"
#include "Matrix4.h"
#include "Polygon.h"
#include <iostream>

using namespace System;

// methods for debug purposes

void print(const Matrix3 &m) {
	for (int i = 0; i < m.dim; i++) {
		if (i == 0) std::cout << "{ "; 
		else std::cout << std::endl << "  ";
		for (int j = 0; j < m.dim; j++) {
			std::cout << m.get(i, j) << " ";
		}
	}
	std::cout << "}" << std::endl;
}

void print(const Matrix4 &m) {
	for (int i = 0; i < m.dim; i++) {
		if (i == 0) std::cout << "{ "; 
		else std::cout << std::endl << "  ";
		for (int j = 0; j < m.dim; j++) {
			std::cout << m.get(i, j) << " ";
		}
	}
	std::cout << "}" << std::endl;
}

void print(const Vector3 &v) {
	std::cout << "(" << v.x << "; " << v.y << "; " << v.z << ")" << std::endl;
}

void print(const Vector4 &v) {
	std::cout << "(" << v.x << "; " << v.y << "; " << v.z << "; " << v.w <<  ")" << std::endl;
}

void print(const Polygon &p) {
	std::cout << "Poly:" << std::endl;
	for (const Vector4 &vert : p.vertices) {
		print(vert);
	}
}

void print(char* str) {
	std::cout << str << std::endl;
}

int main(array<System::String ^> ^args)
{
	Matrix4 trans(std::vector<float> { 1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 1, 3, 0, 0, 0, 1 });
	Matrix4 scale(std::vector<float> { 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1 });
	Vector4 v1;
	Vector4 v2(5, -3, 1, 1);

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

	Polygon p(std::vector<Vector3> {
		Vector3(0, 0, 0),
		Vector3(2, 0, 0),
		Vector3(0, 3, 0),
	});
	print(p);

	p.transform(trans);
	print("translate 1 up 2 right 3 z:");
	print(p);
	p.transform(scale);
	print("scale by 2");
	print(p);


	std::getchar();
    return 0;
}
