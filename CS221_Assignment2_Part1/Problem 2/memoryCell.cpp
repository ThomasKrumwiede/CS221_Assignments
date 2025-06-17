/*  memoryCell.cpp
	12/3/24
	Thomas Krumwiede
	implementation of the class memoryCell that is
	required for Assignment 2 question 2*/
#include <iostream>
#include <stdlib.h>
#include "sharedString.h"
using namespace std;


// Construct a memory cell from a char array
SharedString::MemoryCell::MemoryCell(const char* right)
{
   count = 0;
   int n = 0;
   while (right[n] != '\0')
      n++;
   buffer = new char[1 + n];
   for (int i = 0; i < n; i++)
      buffer[i] = right[i];
   buffer[n] = '\0';
}

//The destructor
SharedString::MemoryCell::~MemoryCell()
{
   delete[] buffer;
}

