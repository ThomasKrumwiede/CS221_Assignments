// list.h
//
// A class implementing a linked list of integers.
//
#include <iostream>
using namespace std;

class List;
class Iterator;

#ifndef LIST_H
#define LIST_H

class List{
public:
    List ();  // constructor
    ~List (); // destructor

    void frontInsert (int value);  // insert at front of list
    void rearInsert (int value);   // insert at rear of list
	int frontDelete();
	int rearDelete();
	int length() const;

    //Part D member function using the iterator class 

    /*Method to return an iterator with current pointing to the first node in a list and previous pointing to NULL
    @peram void
    @return Iterator */
    Iterator begin();

    /*Method to return an iterator with current pointing to NULL and the previous pointing to the last element
   @peram void
   @return Iterator */
    Iterator end();

    /*Method to insert a new node containing an int value into the linked list 
   @peram Iterator and Int
   @return void */
    void insert(Iterator iter, int insert_dateValue);

    /*Method to delete a node at the current iterator and set the iterator after the removed element 
   @peram Iterator
   @return Iterator */
    Iterator delete_node(Iterator iter);

    friend ostream& operator<< (ostream& out, List& l);  // print the list

    
protected:
    struct Node
    {
        int  data;
        Node *next;
    };

	Node* first;
    Node* last;

    friend class Iterator;
};

#endif
