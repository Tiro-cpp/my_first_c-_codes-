#include <iostream>
#include "my_vector_cpp.hpp"

void Vector::init (size_t capacity) {
	_capacity = capacity;
	data = new int[capacity]; 	
}

void Vector::init (size_t capacity , int value) {
	_capacity = capacity;	
	data = new int[capacity];
	for(int i{0}; i < capacity; ++i) data[i] = value;	
}

void Vector::destroy () {
	delete[] data;
	data = nullptr;
	_capacity = _size = 0;
}

void Vector::clear () {_size = 0;}

size_t Vector::size () const {return _size;}

size_t Vector::capacity () const {return _capacity;}

void Vector::realloc_helper() {

	int* arr = new int[_capacity * 2];
	_capacity = 2 * _capacity;
	for(int i{0}; i < _size ; ++i) arr[i] = data[i];
	delete[] data;
	data = arr;
}

void Vector::push_back (int value) {

	if(_size == _capacity) realloc_helper();
	data[_size] = value;
	++_size;
}
void Vector::pop_back () {--_size;}

void Vector::insert (size_t index , int value) {
	if(index > _size) {
		std::cout<< "ERROR:___UNDEFINE BEHAVIOR";
		return;
	}
	if(_size == _capacity) realloc_helper();
	
	for(size_t i = _size; i >= index; --i) {
		data[i] = data[i - 1];
	}	

	data[index] = value;
	++_size;
}
void Vector::erase (size_t index) {
	if(index >= _size) {
	std::cout<< "ERROR:____UNDEFINE BEHAVIOR___" ;
	return;
	}
	for(int i = index ; i < _size ; ++i) data[i] = data[i+1];
	--_size;
}

