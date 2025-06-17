#pragma once;
#include <iostream>
#include <string>
#include "treeNode.h"
using namespace std;

class Action {
public:
	/*This function will add the string "Problem 3" to the data field of each node
	@peram String&
	@Return void */
	virtual void act(string& str);
};