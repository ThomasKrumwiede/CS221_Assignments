/*Problem3.cpp
CS221 Assignment 1 Problem 3
Thomas Krumwiede 
10/25/24
This file contains the main fucntion to test Problem 3 part a and b*/
#include <iostream>
#include <string>
#include "bintree.h"
using namespace std;

int main()
{  
   BinarySearchTree t;
   t.insert("D");
   t.insert("B");
   t.insert("A");
   t.insert("C");
   t.insert("F");
   t.insert("E");
   t.insert("I");
   t.insert("G");
   t.insert("H");
   t.insert("J");
   t.print();
   cout << "Removing A, B, F, D" << endl;
   t.erase("A"); // Removing leaf
   t.erase("B"); // Removing element with one child
   t.erase("F"); // Removing element with two children
   t.erase("D"); // Removing root
   t.print();
   cout << t.count("E") << "\n";
   cout << t.count("F") << "\n";

   //Problem 3
   BinarySearchTree problem3Tree;
   problem3Tree.insert("E");
   problem3Tree.insert("B");
   problem3Tree.insert("A");
   problem3Tree.insert("C");
   problem3Tree.insert("F");
   problem3Tree.insert("G");

   //Problem 3 part A
   cout << '\n' << "Problem 3 part A: " << endl; 
   cout << "Test printLevel(0): ";
   problem3Tree.printLevel(0);
   cout << '\n' << "Test printLevel(1): ";
   problem3Tree.printLevel(1);
   cout << '\n' << "Test printLevel(2): ";
   problem3Tree.printLevel(2);
   cout << '\n' << "Test printLevel(3): ";
   problem3Tree.printLevel(3);
   //return 0;

   //Problem 3 Part B
   cout << '\n' << "Problem 3 part B: " << endl;

   Action action;
   problem3Tree.postorder(&action);

   return 0;
}
