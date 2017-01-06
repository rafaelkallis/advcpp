
#include "dumb_pointer.h"
#include "smart_pointer.h"
#include <cassert>
#include <iostream>

class test_object_t {
public:
	int func(){ return 1; }
};

void func(smart_pointer<test_object_t> smart_ptr){ return; }

void test_smart_pointer() {
	test_object_t * test_object1 = new test_object_t();
	test_object_t * test_object2 = new test_object_t();

	// contructor
  	smart_pointer<test_object_t> smart_ptr1(test_object1);
  	assert(smart_ptr1.counter() == 1);

	// copy constructor
	smart_pointer<test_object_t> smart_ptr2(smart_ptr1);
	assert(smart_ptr1.counter() == 2);
	assert(smart_ptr2.counter() == 2);

	smart_pointer<test_object_t> smart_ptr3(test_object2);
  	assert(smart_ptr3.counter() == 1);

	// = operator
	smart_ptr2 = smart_ptr3;
	assert(smart_ptr1.counter() == 1);
	assert(smart_ptr2.counter() == 2);
	assert(smart_ptr3.counter() == 2);

	func(smart_ptr1);
	func(smart_ptr2);
	func(smart_ptr3);

	// no destruction after pass by value
	assert(smart_ptr1.counter() == 1);
	assert(smart_ptr2.counter() == 2);
	assert(smart_ptr3.counter() == 2);

	// * operator
	assert((*smart_ptr1).func() == 1);
	assert((*smart_ptr2).func() == 1);
	assert((*smart_ptr3).func() == 1);


	// -> operator
	assert(smart_ptr1->func() == 1);
	assert(smart_ptr2->func() == 1);
	assert(smart_ptr3->func() == 1);
}

void test_dumb_pointer() {
	dumb_pointer<test_object_t> ptr(new test_object_t());
	assert((*ptr).func() == 1);
	assert(ptr->func() == 1);
}

int main(){
	test_dumb_pointer();
	test_smart_pointer();
	std::cout << "All tests passed" << std::endl;
	return 0;
}