/*  sharedString.h
    12/3/24
    Thomas Krumwiede
    declaration of the class shared string and memoryCell
    that are required for Assignment 2 question 2*/
#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
/**
A SharedString object contains a pointer to a memory cell
that can be shared with other SharedString objects
The memory cell has a reference counter and a dynamically 
allocated array of characters
The assignment operator and the copy constructor do not copy
the array of characters, but only the pointer to the memory
cell and increment the reference counter for the array of cha-
racters. The destructors decrements the reference counter but
only deallocates memory when the reference counter becomes 0. 
**/
class SharedString 
{
public:
   SharedString();
   SharedString(const char* right);
   SharedString(const SharedString& right);
   ~SharedString();
   SharedString& operator=(const SharedString&);

   //Comparison operator overloads 
   bool operator<(const SharedString& right) const;
   bool operator==(const SharedString& right) const;
   bool operator>(const SharedString& right) const;

   //[] Operator overload 
   char& operator[](int index); 

private:
   class MemoryCell;
   MemoryCell* cellPtr;
   void reassignMemory(MemoryCell*);
   int compare(const SharedString& right) const; //Private compare function 
};

//class SharedString::StringReference 
class SharedString::MemoryCell
{
public:
   int count;
   char* buffer;
   MemoryCell(const char* right);
   ~MemoryCell();
};

