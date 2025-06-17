#pragma once;
#include <iostream>
#include <string>
#include "treeNode.h"
using namespace std;

class BinarySearchTree
{
public:
   BinarySearchTree();
   void insert(string data);
   void erase(string data);
   int count(string data) const;
   void print() const;

   /*print the value of the data members of all the nodes at a specific height 
   @Peram int
   @return void*/
   void printLevel(int level);

   /*Use the function in the Action class and print the nodes in post order
   @Peram Action*
   @Return void*/
   void postorder(Action* a);

private:
   TreeNode* root;
};
