// testApp.cpp : main project file.

#include "stdafx.h"
#include "Vector3.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{
	Vector3 b(3, 4, 0);
	b.print();
	std::cout << b.len << std::endl;
	Vector3 bnorm = -b;
	std::cout << bnorm.len << std::endl;
	bnorm.print();

	b.print();
    Console::WriteLine(L"Hello World");
	std::getchar();
    return 0;
}
