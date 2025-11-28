#ifndef HEADER_HPP
#define HEADER_HPP


class Vector {
private:	
    int* data;
    size_t _size;
    size_t _capacity;


public:
	Vector(int* Data = nullptr, int size = 0, int capacity = 0 ): data(Data),_size(size), _capacity(capacity) {}
	
	Vector(const Vector& oth) : _size(oth._size), _capacity(oth._capacity), data(nullptr) {
		data = new int[oth._capacity];
		if (!oth.data) return;
	
		for (size_t i{0}; i < oth._size; ++i) {
			data[i] = oth.data[i];
		}
	}

	Vector& operator=(const Vector& oth) {
		if(this == &oth) return *this;

		_size = oth._size;
		_capacity = oth._capacity;

		delete[] data;
		data = new int[oth._capacity];

		for(size_t i{0}; i < oth.size() ; ++i) {
			data[i] = oth.data[i];
		}
	}

	Vector(Vector&& oth) : _size{oth._size}, _capacity{oth._capacity}, data{oth.data} {
		oth.data = nullptr;
		oth._size = oth._capacity = 0;
	} 


	Vector& operator=(Vector&& oth ) {
		if (this == &oth )return *this;

		_size = oth._size;
		_capacity = oth._capacity;
		delete []data;
		data = oth.data;
		oth.data = nullptr;
	}




	~Vector() {
		delete[] data;
		_capacity = _size = 0;
	}	

public:
	
	

	

	
	void clear();
	int* get_data() const { return data; }
	
	size_t size() const;
	size_t capacity() const;
	void realloc_helper();
	void push_back(int);
	void pop_back();

	void insert(size_t, int); // insert at index (0..size)
	void erase(size_t); // erase element at index (0..size-1)

	
};

#endif
