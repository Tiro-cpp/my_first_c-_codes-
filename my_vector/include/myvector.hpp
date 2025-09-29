#ifndef HEADER_HPP
#define HEADER_HPP


struct MyVector {
    int* data;
    size_t size;
    size_t capacity;
};


void myvector_init(MyVector* v, size_t);

void myvector_init(MyVector*, size_t, int);//init with default vals

void myvector_destroy(MyVector*);
void myvector_clear(MyVector*);

size_t myvector_size(const MyVector*);
size_t myvector_capacity(const MyVector*);

void myvector_push_back(MyVector*, int);
void myvector_pop_back(MyVector*);

void myvector_insert(MyVector*, size_t, int); // insert at index (0..size)
void myvector_erase(MyVector*, size_t); // erase element at index (0..size-1)

void myvector_print(const MyVector*);


#endif
