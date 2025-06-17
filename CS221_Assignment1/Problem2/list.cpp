/*List.cpp
CS221 Assignment 1 Problem 2
Thomas Krumwiede
10/25/24
This file contains the functions for List class for problem 2*/
#include <cassert>
#include <iostream>
#include "list.h"
#include "Iterator.h"
using namespace std;

// Constructor
List::List ()
{
   first = NULL;
   last = NULL;
}

// Destructor
List::~List (){
    Node *next_node;

    while (first != NULL){
        next_node = first->next;
        delete first;
        first = next_node;
    }
}

// Insert at front of list
void List::frontInsert (int value){
    Node *new_node;

    new_node = new Node;
	//Make sure that the new node is not NULL 
    if (new_node == NULL){
        cout << "Unable to allocate memory. Insertion cancelled." << endl;
        return;
    }

	//Check to see if the node being inserted will be the only node in the list 
	//if new_node is the only node in the list set last to point to new_node
	if (first == NULL) {
		last = new_node;
	}

	//Insert new_node at the front of the list if the list is not empty
    new_node->data = value;
    new_node->next = first;
    first = new_node;
}

// Insert at rear of list
void List::rearInsert (int value)
{
    Node *new_node, *current;

    new_node = new Node;
    if (new_node == NULL)
    {
        cout << "Unable to allocate memory. Insertion cancelled." << endl;
        return;
    }
    new_node->data = value;
    new_node->next = NULL;
	if (first == NULL) {
		first = new_node;
		last = new_node;
	}
    else
    {
        current = last;
        //while (current->next != NULL) 
			//current = current->next;
        current->next = new_node;
		last = new_node;
    }
	///does not maintain last
}

int List::frontDelete(){
	assert(first != NULL);
	Node * temp = first;
	int value = first->data;
	first = first->next;
	delete temp;
	return value;
}

int List::rearDelete(){	
	assert(first != NULL);
	int value;
	if (first->next == NULL) {// there is a single node in thelist
		value = first->data;
		delete first;
		first = NULL;
	}
	else{     // need to traverse the list
		Node * current = first->next;
		Node * previous = first;
		while (current->next != NULL){
			previous = current;
			current = current->next;
		}
		value = current->data;
		delete current;
		previous->next = NULL;
	}
	return value;		
}

int List::length() const{
	int len = 0;
	Node* current = first;
	while (current != NULL){
		len++;
		current = current->next;
	}
	return len;		
}

// Print the list
ostream& operator<< (ostream& out, List& l)
{
	List::Node *current = l.first;

	while (current != NULL)
	{
		out << current->data << ' ';
		current = current->next;
	}
	return out;
}


//Problem 2 Part D Member function 
Iterator List::begin() {
	Iterator iter;
	iter.previous_node = NULL;
	iter.current_node = first;
	iter.container = this;
	return iter;
}

Iterator List::end() {
	Iterator iter;
	iter.previous_node = last;
	iter.current_node = NULL;
	iter.container = this;
	return iter;
}

void List::insert(Iterator iter, int insert_dateValue) {
	//Case1: the iterator is at the begining of the linked list 
	if (iter.previous_node == NULL) {
		frontInsert(insert_dateValue);
		return;
	}

	//Case2: the iterator is at the very end of the list 
	if (iter.current_node == NULL && iter.previous_node == last) {
		rearInsert(insert_dateValue);
		return;
	}

	//Case3: the iterator is currently between the first and last element
	Node* new_node;
	new_node = new Node;

	//Make sure that the new node is not NULL 
	if (new_node == NULL) {
		cout << "Unable to allocate memory. Insertion cancelled." << endl;
		return;
	}
	//set the data value of new_node 
	new_node->data = insert_dateValue;
	//set the next value to point to the current_node
	new_node->next = iter.current_node;

	//set the next pointer of the previous not to new_node
	iter.previous_node->next = new_node;

	//set the previous_node pointer at the current itterator to new_node
	iter.previous_node = new_node;

	return;
}


Iterator List::delete_node(Iterator iter) {
	Iterator returnIter; //create a new iterator to return and set the values 

	//Case1: the iterator is at the begining of the linked list 
	if (iter.previous_node == NULL) {
		returnIter.container = this;
		returnIter.previous_node = NULL;
		returnIter.current_node = first;

		frontDelete();

		return returnIter;
	}

	//Case2: the iterator is at the very end of the list 
	if (iter.current_node == NULL && iter.previous_node == last) {
		returnIter.container = this;
		returnIter.previous_node = last;
		returnIter.current_node = NULL;

		rearDelete();

		return returnIter;
	}

	//Case3: if the iterator is in the middle of the list 
	iter.previous_node->next = iter.current_node->next; //set the next value of the previous node 

	returnIter.container = this;
	returnIter.previous_node = iter.previous_node;
	returnIter.current_node = iter.current_node->next;
	
	delete iter.current_node; //delete the desired node 

	return returnIter;
}