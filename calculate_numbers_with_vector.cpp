#include <iostream>
#include <vector>
void calculate_numbers ( std::vector<int>& array , int& num1 , int& num2) {
	
	for (size_t i {0} ; i < array.size() ; ++i ) {
		num1 = num1 + array[i];

	}
	
	num2 = num1 / array.size();
}
