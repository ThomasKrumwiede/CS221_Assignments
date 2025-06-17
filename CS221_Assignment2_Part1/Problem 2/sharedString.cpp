/*  sharedString.cpp
	12/3/24
	Thomas Krumwiede
	implementation of the class sharedString that is 
	required for Assignment 2 question 2*/
#include <iostream>
#include <stdlib.h>
#include "sharedString.h"
using namespace std;

SharedString::SharedString() : cellPtr(NULL)
{
   cout << "\tEntering default constructor SharedString().\n";
   cout << "\tCell pointer is NULL. There is no memory buffer.\n";
}

SharedString::SharedString(const char* right) : cellPtr(NULL) 
{
   cout << "\tEntering constructor SharedString(const char*). \n";
   //Create a new memory cell with reference counter 0
   //and a copy of the array right 
   //and repoint the memory pointer to it
   reassignMemory(new MemoryCell(right));
}

SharedString::SharedString(const SharedString& right):cellPtr(NULL)
{
   cout << "\tEntering copy constructor SharedString(const SharedString&). \n";
   // Construct a new SharedString by copying the memory pointer
   // of the argument and incrementing the reference counter
   // of the memory cell pointed to by this memory pointer
   reassignMemory(right.cellPtr);
}

SharedString::~SharedString()
{
   cout << "\tEntering destructor ~SharedString(). \n";
   //Decrement the reference counter in the memory cell
   //When the reference coiunter becomes 0, 
   //release the memory cell
   reassignMemory(NULL);
}

SharedString& SharedString::operator=(const SharedString& right)
{
   cout << "\tEntering assignent operator=(const SharedString&). \n";
   // Decrement the reference counter of the memory cell
   // of the left side of the assignment. Copy the memory
   // pointer of the right side into the left side
   // and increment the reference counter of the memory cell
   // now poited to by both the left and the right side 
   // SharedString objects.
   reassignMemory(right.cellPtr);
   return *this;
}

void SharedString::reassignMemory(SharedString::MemoryCell* newCellPtr)
{
	// Called from destructor
	if (newCellPtr == NULL) // Print memory cell before change
		cout << "\tReassign. Destructor. Memory cell before change: " 
		<< cellPtr->buffer
		<< ", count: " << cellPtr->count << ".\n";
   
	else {// First increment count on the new value
		newCellPtr->count += 1;
		cout << "\tReassign: Incremented count of " << newCellPtr->buffer
			<< " to " << newCellPtr->count <<".\n";
	}
   
   // In case of assignment or destructor need to decrement 
   // reference count in the current memory cell of the left side
   if (cellPtr != NULL)  
   {
      cellPtr->count -= 1;
	  cout << "\tReassign. Assignment or destructor. Old memory cell: "
		  << cellPtr->buffer << ". Decremented count to: " 
		  << cellPtr->count << ".\n";
	  if (cellPtr->count == 0){
		  cout << "\tReassign. Deallocating " << cellPtr->buffer << ".\n";
		  delete cellPtr;
	  }
   }
   // Finally, reassign the memory cell pointer
   cellPtr = newCellPtr;  // Change binding
   if (cellPtr != NULL) // Print new values
	   cout << "\tAfter reassign, memory cell is " << cellPtr->buffer
	   << ", count: " << cellPtr->count << ".\n";
}

//Compare function 
int SharedString::compare(const SharedString& right) const {
	if (cellPtr == nullptr && right.cellPtr == nullptr) {
		return 0; // Both are empty
	}
	else if (cellPtr == nullptr) {
		return -1; // Current string is empty
	}
	else if (right.cellPtr == nullptr) {
		return 1; // Right-hand string is empty
	}

	// Perform lexicographical comparison of the character buffers
	return strcmp(cellPtr->buffer, right.cellPtr->buffer);
}

//Comparison operator overloads 
bool SharedString::operator<(const SharedString& right) const {
	return compare(right) < 0;
}

bool SharedString::operator==(const SharedString& right) const {
	return compare(right) == 0;
}

bool SharedString::operator>(const SharedString& right) const {
	return compare(right) > 0;
}

//[] Overload 
char& SharedString::operator[](int index) {
	if (cellPtr == nullptr || index >= strlen(cellPtr->buffer)) {
		throw out_of_range("Index out of bounds");
	}
	// If the string is shared (reference count > 1)
	if (cellPtr->count > 1) {
		// Create a new memory cell with the same content
		MemoryCell* newCell = new MemoryCell(cellPtr->buffer);

		// Decrement reference count of current memory cell
		cellPtr->count--;

		// Reassign to the new memory cell
		cellPtr = newCell;

		cout << "changing letter, new copy creaeted\n";
	}

	// Return the character reference for modification
	return cellPtr->buffer[index];
}