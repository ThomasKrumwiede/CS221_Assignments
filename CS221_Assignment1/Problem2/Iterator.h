#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include "list.h"
using namespace std;


class Iterator
{
public:
	/** Gets the data field of the given node 
	@Return the int value of the current node data field
	*/
	Iterator(); 

	/*Method to get the data of a node
   @peram void
   @return int */
	int get();

	/*move the iterator to the next node and set the previous node to the last node
   @peram void
   @return void */
	void next();

	/*move the iterator to the previous node 
   @peram void
   @return void */
	void previous();

	/*compare two iterators 
   @peram Iterator
   @return bool */
	bool equals(Iterator b) const;

private:
	List::Node* previous_node;
	List::Node* current_node;

	List* container;

	friend class List;
};