#include <iostream>
#define pi 3.14

void area(double radius) {
	std::cout << "circle" << pi*radius*radius << std::endl;
}

void  area(int width, int height) {
	 std::cout << "rectangle" << width * height << std::endl;
}

void  area(double base, double height) {
	std::cout << "triangle" << (base * height) / 2 << std::endl;
}

