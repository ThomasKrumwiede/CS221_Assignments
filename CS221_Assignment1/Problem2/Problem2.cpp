/*Problem2.cpp
CS221 Assignment 1 Problem 2
Thomas Krumwiede
10/25/24
This file contains the main function used to test problem 2*/
#include <iostream>
#include "list.h"
#include "Iterator.h"
using namespace std;


int main ()
{
   List l;

   cout << "List created." << endl;
   l.rearInsert (10);
   l.rearInsert (20);
   cout << "Two data values inserted in rear." << endl;
   l.frontInsert (30);
   l.frontInsert (40);
   cout << "Two data values inserted in front." << endl;
   cout << "The list is: " << l << endl;
   while (l.length() > 0){
	   int value = l.frontDelete();
	   cout << "Deleted from the front " << value << endl;
	   cout << "The list length is " << l.length() << endl;
	   cout << "The list is: " << l << endl;	  
	   if (l.length() <=0) break;
	   value = l.rearDelete();
	   cout << "Deleted from the end " << value << endl;
	   cout << "The list length is " << l.length() << endl;
	   cout << "The list is: " << l << endl;
	   
   }  

   //Test the additions required from Assignment 1 Problem 2
   cout << "\n" << "Assingment 1 Problem 2:" << endl;
   cout << "Note: every iteration through the list uses equals() in the loop, therefore it is being tested on every output" << endl;

   List problem2list;
   problem2list.frontInsert(2);
   problem2list.frontInsert(1);
   problem2list.rearInsert(3);
   problem2list.rearInsert(4);
   problem2list.rearInsert(5);
   problem2list.rearInsert(6);

   //test part c
   //declare iterators 
   Iterator position_begin;
   Iterator position_end;
   //Test List::begin()
   //iterate through the list with next
   position_begin = problem2list.begin();
   position_end = problem2list.end();
   cout << '\n' << "Testing begin() and next() to iterate through the list " << endl;
   while (!position_begin.equals(position_end)) {
		cout << "postition_begin = " << position_begin.get() << endl;
		position_begin.next();
   }
   

   //Test List::end() 
   //Iterate through the list with previous()
   position_begin = problem2list.begin();
   position_end = problem2list.end();
   cout << '\n' << "Testing end() and previous() to iterate through the list " << endl;
   while (!position_end.equals(position_begin)) {
	   cout << "position_end = " << position_end.get() << endl;
	   position_end.previous();
   }
   
   //Test of the insert method for as node in the middle of the list 
   position_begin = problem2list.begin();
   for (int i = 0; i < 3; i++) {
	   position_begin.next();
   }

   problem2list.insert(position_begin, 99);

   //Test inserting at the begining and the end 
   position_begin = problem2list.begin();
   problem2list.insert(position_begin, 99);

   position_end = problem2list.end();
   problem2list.insert(position_end, 99);

   position_begin = problem2list.begin();

   //print the linked list 
   cout << '\n' << "Testing the insert() on the begining, middle and end of the linked list: " << endl;
   while (!position_begin.equals(position_end)) {
	   cout << "postition_begin = " << position_begin.get() << endl;
	   position_begin.next();
   }
   
   //Test delete_node()
   //Test deletitng at the beginging and the end of the list 
   position_begin = problem2list.begin();
   //problem2list.insert(position_begin, 99);

   position_end = problem2list.end();
  // problem2list.insert(position_end, 99);

   problem2list.delete_node(position_begin); //delete the first node in the linked list 
   problem2list.delete_node(position_end); // delete the last node in the linked list 

   //delet the node that was added to the middle of the list 
   position_begin = problem2list.begin();
   for (int i = 0; i < 3; i++) {
	   position_begin.next();
   }

   //print the linked list 
   position_begin = problem2list.begin();
   cout << '\n' << "Test the delete_node function by deleteing the nodes that were inserted:  " << endl;
   while (!position_begin.equals(position_end)) {
	   cout << "postition_begin = " << position_begin.get() << endl;
	   position_begin.next();
   }
   return 0;
}