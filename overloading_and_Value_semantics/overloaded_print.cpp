#include <iostream>

void print_to (int num ) {

	std::cout << num << std::endl;
}

void print_to (std::string& str ) {

	std::cout << str << std::endl;
}

void print_to (int* arr) {

	for(int i{0} ; i < 6 ; ++i ) {
		std::cout << arr[i] << std::endl;
		
	}

}
