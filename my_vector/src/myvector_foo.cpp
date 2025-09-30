#include <iostream>
#include "myvector.hpp"



void myvector_init(MyVector* v, size_t capacity) {
	v->data = new int[capacity];
	
	v->capacity = capacity;
	v->size = 0;
}


void myvector_destroy(MyVector* v) {
	delete[] v->data;
	v->data = nullptr;

	v->capacity = v->size = 0;
}

void myvector_clear(MyVector* v) { v->size = 0; }

size_t myvector_size(const MyVector* v) { return v->size; }

size_t myvector_capacity(const MyVector* v) { return v->capacity; }


void realloc_helper(MyVector* v) {
	int* arr = new int[v->capacity * 2];
	v->capacity = v->capacity * 2;

	for (size_t i{0}; i < v->size; ++i) {
		arr[i] = v->data[i];
	}

	delete[] v->data;
	v->data = arr;

}

void myvector_push_back(MyVector* v, int value) {
	if(v->size == v->capacity) {
		realloc_helper(v);
	} 

	v->data[v->size] = value;
	++(v->size);

}

void myvector_pop_back(MyVector* v) { --(v->size); }

void myvector_insert(MyVector* v, size_t index, int value) {
	if(index > v->size){
		printf("ERROR:___UNDEFINE BEHAVIOR");
		return;
	}
	
	if (v->size == v->capacity) realloc_helper(v);
	
	for(size_t i = v->size; i > index; --i) {
		v->data[i] = v->data[i - 1];
	}	

	v->data[index] = value;
	++(v->size);

} 




void myvector_erase(MyVector* v, size_t index) {
	if(index >= v->size || v->size == 0){
		std::cout<< "ERROR:___UNDEFINE BEHAVIOR" << std::endl;
		return;
	}

	--(v->size);
	for(size_t i = index; i < v->size; ++i) {
		v->data[i] = v->data[i+1];
    }
}


void myvector_print(const MyVector* v) {
	for(size_t i{0}; i < v->size ; ++i) {
		std::cout << v->data[i] << " "; 
	}
	std::cout << std::endl;
}






