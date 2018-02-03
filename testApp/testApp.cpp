// testApp.cpp : main project file.

#include "stdafx.h"
#include "Vector3.h"
#include "Matrix3.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{
	Matrix3 id;
	id.print();
	Matrix3 id2 = id + id;
	id2.print();
	Matrix3 a(std::vector<float> {1, 2, 3, 4, 5, 6, 7, 8, 9});
	a.print();
	Matrix3 a2 = a * 2;
	a2.print();
	a2.transposed().transposed().print();
    Console::WriteLine(L"Hello World");
	std::getchar();
    return 0;
}
