#ifndef HEADER_HPP
#define HEADER_HPP

class Single_List {
public:

	struct Node {
        int val;
        Node* next;
	Node(int _val = 0, Node* _next = nullptr): val{_val}, next{_next} {}
  
	};
private:
	Node* head;	

public:
	void push_back(int val);
	void copy_(const Single_List& rhs); 
	void print_();	
	void delete_();
public:


	Single_List(): head{nullptr} {}
	Single_List(int count, int val);
	Single_List(std::initializer_list<int> list);	
	Single_List(const Single_List& rhs);
	Single_List( Single_List&& rhs);
	Single_List& operator=(const Single_List& rhs);
	Single_List& operator=(Single_List&& rhs);
	~Single_List();

public:
//Operator Overloading

	friend Single_List operator+(Single_List lhs, Single_List rhs);
	Single_List& operator+=(Single_List rhs);
	friend bool operator==(Single_List& lhs,Single_List& rhs);
	friend bool operator!=(Single_List& lhs,Single_List& rhs);
	int& operator[](size_t index);



};




#endif
