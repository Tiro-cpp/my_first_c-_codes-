#include <iostream>
#include "header.hpp"
#include <vector>
int main () {
	

/*
	std::string name; 
	int age = 0;
	std::cout << "enter your name";
	std::cin >> name;
	std::cout << "enter your age ";
	std::cin >> age; 
	std::cout<<"hello " << name << " jan your age is " << age; 
*/

/*	int x =0;
	int y =0;
	std::cout << "enter two integers ";
	std::cin >> x;
	std::cin >> y;
	std::cout << x << y;
	swap_with_reference( x , y );
	
	std::cout << x << y;
	 
*/


/*	std::string name; 
        std::cout << "enter your name";
		
	
	std::cin >> name;

	reverse_name(name);

	std::cout << name << std::endl;
*/

	

/*	int N = 0;
	int sum = 0;
	int num = 0;
	std::cout << "haw many numbers you want to input:  ";
	std::cin >> N;
	std::vector <int> array( N , 0);
	std::cout << "enter numbers in array";
	for(int i{0} ; i < array.size() ; ++i) {
		std::cin >> array[i];
		
	}
		
	calculate_numbers (array , sum , num );
	std::cout << "array sum is " << sum << std::endl;
	std::cout << "array average is " << num <<std::endl;
*/
	int N = 0;
        int large = 0;
        int small = 0;
        std::cout << "haw many numbers you want to input:  ";
        std::cin >> N;
        std::vector <int> array( N , 0);
        std::cout << "enter numbers in array";
        for(int i{0} ; i < array.size() ; ++i) {
                std::cin >> array[i];
                  
          }
        largest_smallest( array , large , small );          
	std::cout << "small " << small << std::endl;
        std::cout << "large " << large << std::endl;
	



return 0;
}
