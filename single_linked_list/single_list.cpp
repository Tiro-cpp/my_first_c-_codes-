#include <iostream>
#include "single_list.hpp"

void Single_List::push_back(int val) {
	if(!head){
	   head =new Node(val);
        }else {
           Node* tmp = head;
           while(tmp->next) tmp = tmp->next;
  	   tmp->next = new Node(val);
 	} 
}
void Single_List::delete_() {
	while(head) {
          Node* current = head;
          head = head->next;
          delete current;
	}
	head = nullptr;
}

void Single_List::copy_(const Single_List& rhs) {
		
	const Node* tmp = rhs.head;
	Node Dummy(0);
	Node*tmp2 = &Dummy;
	
	while(tmp){
	tmp2->next = new Node(tmp->val);
	tmp2 = tmp2->next;
	tmp = tmp->next;	
	}
	this->head=Dummy.next;


}
void Single_List::print_(){
	Node* ths = head;
	while(ths){
	std::cout << ths->val<<",";
	ths = ths->next;
	}
	
}
Single_List::Single_List(int count, int val) {
	for(size_t i{0}; i < count ; ++i) {
		push_back(val);
	}
		
}

Single_List::Single_List(std::initializer_list<int> list): head{nullptr} {

	for(int val : list) {
		push_back(val);
	}
}
Single_List::Single_List(const Single_List& rhs): head{nullptr} {
	copy_(rhs);

}
Single_List::Single_List( Single_List&& rhs): head{rhs.head}  {
	rhs.head = nullptr;
}
Single_List::~Single_List() {
	delete_();
	std::cout << "dtor\n" << std::endl;
}

Single_List& Single_List::operator=(const Single_List& rhs) {
	if(head != rhs.head ){	
	delete_();
	copy_(rhs);
	}
	return *this;	

}

Single_List& Single_List::operator=(Single_List&& rhs) {
	if(head != rhs.head){
	delete_();
	head = rhs.head;
	rhs.head = nullptr;
	}
	return *this;
}


////


Single_List& Single_List::operator+=(Single_List rhs) {
	Node* tmp = this->head;
	while(tmp && tmp->next) tmp = tmp->next;
	if (!tmp) {
		head = rhs.head;
		rhs.head = nullptr;
		return *this;
	}

	tmp->next = rhs.head;
	rhs.head = nullptr;
	return *this;
}

Single_List operator+(Single_List lhs, Single_List rhs) {
	lhs += rhs;
	return lhs;
}

bool operator==(Single_List& lhs, Single_List& rhs) {
	Single_List::Node* ptr1 = lhs.head;
	Single_List::Node* ptr2 = rhs.head;

	while(ptr1 != nullptr && ptr2 != nullptr) {
		if(ptr1->val != ptr2->val) return false;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;		
	}	
	if(!ptr1) return false;
	if(!ptr2) return false;
	return true;
}
 

bool operator!=(Single_List& lhs, Single_List& rhs) {
	return !(lhs == rhs);
}
int& Single_List::operator[](size_t index) {
		Node* ptr = head;
		for(size_t i{0}; i < index; ++i) {
			if(!ptr) std::exit(EXIT_FAILURE);	
			ptr = ptr->next;
		}
		return ptr->val;
}
std::ostream& operator<<(std::ostream& ost, const Single_List& rhs) {
		if(ptr1->val != ptr2->val) return false;
		
}



