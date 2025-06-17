/*  Problem2.cpp 
    12/3/24
    Thomas Krumwiede 
    Main function used to test the program required for Assignment 2 question 2*/
#include <iostream>
#include <stdlib.h>
#include "sharedString.h"
using namespace std;

SharedString g; // Global value

int main()
{
      cout << "Entering main\n";
      cout << "SharedString a = \"Fred\";\n";
   SharedString a = "Fred";
      cout << "SharedString b = \"Alice\";\n";
   SharedString b = "Alice";
      cout << "SharedString c;\n";
   SharedString c;
      cout << "c = a; // Fred\n";
   c = a; // Fred
      cout << "a = b; // Alice\n";
   a = b; // Alice
      cout << "g = b; // Alice\n";
   g = b; // Alice
      cout << "Exiting main\n";
 
      cout << endl << endl << "Assignment 2 Problem 3: " << endl;
      cout << "Test a == b :";
      bool test1 = a == b;
      cout << test1 << endl;

      cout << "Test c == a: ";
      bool test2 = c == a;
      cout << test2 << endl;

      cout << "Test a < c: ";
      bool test3 = a < c;
      cout << test3 << endl;

      cout << "Test changing a letter: " << endl;
      cout << "a and b are Alice" << endl;
      cout << "check if a and b are equal: " << test1 << endl;
      cout << "Changing b to blice" << endl;
      b[0] = 'B';
      bool afterChange = a == b;
      cout << "check if a and b are equal: " << afterChange << endl;


      
   return 0;
}
