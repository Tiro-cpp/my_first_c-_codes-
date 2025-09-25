#include <iostream>
#include <vector>


void largest_smallest (std::vector<int>& array , int& max , int& min ) {

	max = array[0];
	min = array[0];	

	for(size_t i{0} ; i < array.size() ; ++i){
		if( max < array[i] ) max = array[i];
		if( min > array[i] ) min = array[i];
		
	}

}
