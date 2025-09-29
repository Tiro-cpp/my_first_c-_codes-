#include <iostream>

void reverse_name ( std::string& name) {

	int i{0};
	int j = name.size()-1;
	
	while(i < j) {
		char temp =name[i];
		name[i] =name[j];
		name[j] =temp ;	
		++i;
		--j;		

	}



}
