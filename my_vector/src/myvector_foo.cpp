#include <iostream>
#include "myvector.hpp"



void myvector_init(MyVector* v, size_t capacity) {
	
	v -> data = new int[capacity];
	
	v -> capacity = capacity;
	if (capacity > 0) {
		 v -> size =0;
	}
}


void myvector_destroy(MyVector* v) {
	delete[]v->data;
	v->data = nullptr; 
	v->capacity =0;
	v->size =0;

}
void myvector_clear(MyVector* v) {
	v -> size =0;
}

size_t myvector_size(const MyVector* v) {

	
	return v -> size;
}

size_t myvector_capacity(const MyVector* v) {
	return v -> capacity;
}

void myvector_push_back(MyVector* v, int value) {


	if(v->size == v->capacity) {
		
		int* arr = new int[v ->size];
		for(size_t i{0}; i < v->size ; ++i){
			arr[i] = v->data[i];
		}
		delete[] v->data;
		int new_capacity = 2 * v -> capacity;
		 v->data = new int[new_capacity];
	
		for(size_t i{0}; i < v->size ; ++i) {
			v->data[i] = arr[i];		
		}
		delete[] arr;		
		v->data[v->size] = value;
		v->capacity = new_capacity;
		++(v->size);	
	}else{
	v->data[v->size] = value;
	++(v->size);
	}	
}
void myvector_pop_back(MyVector* v) {
		v->size -= 1;		

}

void myvector_insert(MyVector* v, size_t index, int value) {
		if(v->size == v->capacity) myvector_push_back( v, value);
		if(index > v->size){
			printf("ERROR:___UNDEFINE BEHAVIOR");
			return;
		}
		
		for(size_t i = v->size-1; i > index ; --i ) {
			int tmp = v->data[i];
			v->data[i] = v->data[i-1];
			v->data[i-1] = tmp;		
		//	++(v->size);	
		}
} 




void myvector_erase(MyVector* v, size_t index) {
        	if(index >= v->size){
                          std::cout<< "ERROR:___UNDEFINE BEHAVIOR" << std::endl;
                         return;
                  }

		for(size_t i = index; i < v->size ; ++i ) {
                        int tmp = v->data[i];
                        v->data[i] = v->data[i-1];
                        v->data[i-1] = tmp;    
                   
                  }
  		--(v->size);

}
void myvector_print(const MyVector* v) {
	for(size_t i{0}; i < v->size ; ++i) {
		std::cout << v->data[i]<< "." << std::endl;

	}
	



}






