
// Choose which run to compile
#define RUN4 //RUN1 RUN2 RUN3




#ifdef RUN0 

#include"dllist.h"
#include"studentinfo.h"
#include<iostream>

int main() {
	std::cout << StudentInfo::Name() << std::endl;
	std::cout << StudentInfo::ID() << std::endl;

	DLList<int> * l = new DLList<int>;; //DLList of integers

	l->add_rear(1);
	std::cout<< l->front()<<std::endl;
	l->add_front(5);
	std::cout << l->front() << std::endl;
	l->add_front(7);
	std::cout << l->front() << std::endl;
	l->add_front(42);
	l->print();
	l->remove_rear();
	std::cout << l->rear() << std::endl;

	return 0;

}

#elif defined RUN1

#include"dllist.h"
#include"studentinfo.h"
#include<iostream>
#include<string>

int main() {

	std::cout << StudentInfo::Name() << std::endl;
	std::cout << StudentInfo::ID() << std::endl;

	DLList<std::string> * l = new DLList<std::string>; //DLList of integers

	l->add_rear("Hello");
	l->add_front("World");
	l->add_front("Bob");
	l->add_front("2");

	l->print(); // 2 Bob World Hello

	l->remove_rear();  // Will trip assert if empty
	l->print(); // 2 Bob World 

	std::cout << l->front() << std::endl; // 2

	return 0;

}

#elif defined RUN2

#define MAKE_MEMBERS_PUBLIC
#include"dllist.h"
#include<assert.h>

//Unit test example for push_font on initially empty list

int main() {

	// Step 1: Initial state
	// Assume that constructor implemented properly
	// If you're not sure if the constructor is 
	// implemented properly, STOP, go back and make
	// sure. Luckily the default constructor is 
	// done for you.  But the point remains, never,
	// ever, use a function in a test that isn't itself
	// verified to function according to spec.
	DLList<int> * l = new DLList<int>;


	// Step 2: Execute the function to test
	l->add_front(99);

	// Step 3: Verify what you expect to observe.
	// You must know what is supposed to happen in
	// order to analyze for correctness. Generally, 
	// you must permute all possible combinations
	// of all member variables.
	assert(l->head != nullptr);
	assert(l->tail != nullptr);
	assert(l->count == 1);
	assert(l->head->prv() == nullptr);
	assert(l->head->nxt() == nullptr);
	assert(l->head->itm() == 99);

	return 0;
}

#elif defined RUN3 

#define MAKE_MEMBERS_PUBLIC
#include"dllist.h"
#include<assert.h>
#include<string>

//Unit test example for push_font on initially non empty list

int main() {

	// Step 1: Initial state
	// Same as above, except we must head populate the list
	// However, since we are testing add_front, we cannot
	// use it to generate the initial state of our list
	// to test.  So we have to manually set the initial state
	// in this case we are creating a list with three nodes.
	DLList<std::string>::Node* head = new DLList<std::string>::Node;
	DLList<std::string>::Node* second = new DLList<std::string>::Node;
	DLList<std::string>::Node* third = new DLList<std::string>::Node;

	// We have to manually linked everything together:
	head->itm("first");
	head->prv(nullptr);
	head->nxt(second);

	second->itm("second");
	second->prv(head);
	second->nxt(third);

	third->itm("third");
	third->prv(second);
	third->nxt(nullptr);

	// Now we create  DLList object and inject the initial control state:
	DLList<std::string> * l = new DLList<std::string>;
	l->head = head;
	l->tail = third;
	l->count = 3;

	// Step 2: Now with the list given a complete and correct starting state
	// We can test various member functions for correctness.
	// For example we can use this as one test for add_front;
	l->add_front("Zero");

	// Step 3: Verify:  Technically, we should examine all 
	// member variables, and all nodes' value, nxt, prv pointers
	// to ensure that the add_front didn't mangle any of the
	// internal nodes.  But, this is mostly just to illustrate
	// how you might develop your own tests.  
	assert(l->count == 4);
	assert(l->head->prv() == nullptr);
	assert(l->head == head->prv());
	assert(l->head->nxt() == head);
	assert(l->head->itm() == "Zero");
	assert(l->tail == third);

	return 0;
}
#else
//Run unit tests
#include"listtests.h"

int main() {

	//test #1
    for (int i = 0; i <= 1; i++)
        runTest(test_empty,i);
    //test #2
    for (int i = 0; i <= 1; i++)
        runTest(test_add_front,i);
    //test #3
    for (int i = 0; i <= 1; i++)
        runTest(test_add_rear,i);
    //test #4
    for (int i = 0; i <= 6; i++)
        runTest(test_add,i);
    //test #5
    for (int i = 0; i <= 4; i++)
        runTest(test_search,i);
    //test #6
    for (int i = 0; i <= 1; i++)
        runTest(test_front,i);
    //test #7
    for (int i = 0; i <= 1; i++)
        runTest(test_rear,i);
    //test #8
    for (int i = 0; i <= 1; i++)
        runTest(test_peek,i);
    //test #9
    for (int i = 0; i <= 2; i++)
        runTest(test_remove_front,i);
    //test #10
    for (int i = 0; i <= 2; i++)
        runTest(test_remove_rear,i);
    //test #11
    for (int i = 0; i <= 7; i++)
        runTest(test_remove_index,i);
    //test #12
    for (int i = 0; i <= 5; i++)
        runTest(test_remove_item,i);
    //test #13
   for (int i = 0; i <= 1; i++)
        runTest(test_print,i);
    //test #14
    for (int i = 0; i <= 1; i++)
        runTest(test_size,i);
    //test #15
     for (int i = 0; i <= 5; i++)
        runTest(test_items,i);
    //test #16
    for (int i = 0; i <= 2; i++)
        runTest(test_copyCtor,i);
    //test #17
     for (int i = 0; i <= 2; i++)
        runTest(test_assgnOper,i);
    //test #18
    for (int i = 0; i <= 0; i++)
        runTest(test_mem_destructor,i);
    //test #19
    for (int i = 0; i <= 1; i++)
        runTest(test_mem_assgnOper,i);
    //test #20
    for (int i = 0; i <= 12; i++)
        runTest(test_sub_list,i);

	return 0;
}

#endif