/*Iterator.cpp
CS221 Assignment 1 Problem 2
Thomas Krumwiede
10/25/24
This file contains the functions for Iterator class for problem 2*/
#include <string>
#include <iostream>
#include <cassert>
#include "Iterator.h"
using namespace std;

Iterator::Iterator() {
	previous_node = NULL;
	current_node = NULL;
	container = NULL;
}

int Iterator::get() {
    // If current_node is NULL, we are either at the end of the list or before the first element
    if (current_node == NULL) {
        if (previous_node == container->last) {
            cout << "End of the List" << endl;
            previous();
            //return container->last->data;
        }
    }

    //return the data at the current_node
    return current_node->data;
}

void Iterator::next() {
	//assert(this->container != NULL);
	if (current_node == NULL) current_node = container->first;
	else
		previous_node = current_node;
		current_node = current_node->next;
}

void Iterator::previous() {
    // If current_node is NULL, we're at the end of the list, so set it to the last element
    if (current_node == NULL && previous_node == container->last) {
        current_node = container->last;
        previous_node = NULL;
        return;
    }

    // If the current node is the first node, there's no previous node
    if (current_node == container->first) {
        current_node = NULL;
        previous_node = NULL;  // No previous node
        return;
    }

    // Traverse from the beginning to find the node before current_node
    List::Node* temp = container->first;
    List::Node* prev_temp = NULL;

    while (temp != current_node) {
        prev_temp = temp;
        temp = temp->next;
    }

    // Move the iterator to the previous node
    current_node = prev_temp;

    // Update previous_node to reflect the node before current_node
    if (current_node != NULL) {
        temp = container->first;
        prev_temp = NULL;

        while (temp != current_node) {
            prev_temp = temp;
            temp = temp->next;
        }
        previous_node = prev_temp;
    }
    else {
        previous_node = NULL;
    }
}

bool Iterator::equals(Iterator b) const {
	return this->current_node == b.current_node;
}