#ifndef HEADER_HPP
#define HEADER_HPP


class Vector {
private:	
    int* data;
    size_t _size;
    size_t _capacity;


public:
	
	Vector() {
	data = nullptr;
	_size =0;
	_capacity =0;
	}

	~Vector() {
	delete[] data;
	}	

public:
	
	void init(size_t);

	void init(size_t, int);//init with default vals

	void destroy();
	void clear();
	int* get_data() const { return data; }
	
	size_t size() const;
	size_t capacity() const;
	void realloc_helper();
	void push_back(int);
	void pop_back();

	void insert( size_t, int); // insert at index (0..size)
	void erase(size_t); // erase element at index (0..size-1)

	
};

#endif
