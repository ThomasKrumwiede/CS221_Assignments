/*TreeNode.cpp
CS221 Assignment 1 Problem 3
Thomas Krumwiede
10/25/24
This file contains the functions for the TreeNode class required for problem 3*/
#include <iostream>
#include <string>
#include "treeNode.h"
using namespace std;


void TreeNode::insert_node(TreeNode* new_node)
{  
   if (new_node->data < data)
   {  
      if (left == NULL) left = new_node;
      else left->insert_node(new_node);
   }
   else if (data < new_node->data)
   {  
      if (right == NULL) right = new_node;
      else right->insert_node(new_node);
   }
}


bool TreeNode::find(string value) const
{
   if (value < data)
   {
      if (left == NULL) return false;
      else return left->find(value);
   }
   else if (data < value)
   {
      if (right == NULL) return false;
      else return right->find(value);
   }
   else 
      return true;
}

void TreeNode::print_nodes() const
{	
   if (left != NULL)
	   left->print_nodes();
   cout << data << "\n";
   if (right != NULL)
      right->print_nodes(); 
}

void TreeNode::print_nodesLevel(int level) const {
    if (level == 0) {
        cout << data;  // Print the node if we are at the target level
    }
    else {
        if (left != nullptr) {
            left->print_nodesLevel(level - 1);  // Recursively call the left subtree
        }
        if (right != nullptr) {
            right->print_nodesLevel(level - 1); // Recursively call the right subtree
        }
    }
}

void TreeNode::postorderTraversal(Action* a) {
    if (left != nullptr) left->postorderTraversal(a);
    if (right != nullptr) right->postorderTraversal(a);

    a->act(data);
    cout << data << endl;
}
