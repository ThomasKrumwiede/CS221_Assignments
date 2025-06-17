/*binTree.cpp
CS221 Assignment 1 Problem 3
Thomas Krumwiede
10/25/24
This file contains the functions for the binTree class required for problem 3*/
#include <iostream>
#include <string>
#include "bintree.h"
using namespace std;

BinarySearchTree::BinarySearchTree()
{  
   root = NULL;
}

void BinarySearchTree::print() const
{  
   if (root != NULL)
      root->print_nodes();
}

void BinarySearchTree::insert(string data)
{  
   TreeNode* new_node = new TreeNode;
   new_node->data = data;
   new_node->left = NULL;
   new_node->right = NULL;
   if (root == NULL) root = new_node;
   else root->insert_node(new_node);
}

int BinarySearchTree::count(string data) const
{
   if (root == NULL) return 0;
   else if (root->find(data)) return 1;
   else return 0;
}

void BinarySearchTree::erase(string data)
{
   // Find node to be removed

   TreeNode* to_be_removed = root;
   TreeNode* parent = NULL;
   bool found = false;
   while (!found && to_be_removed != NULL)
   {
      if (to_be_removed->data < data)
      {
         parent = to_be_removed;
         to_be_removed = to_be_removed->right;
      }
      else if (data < to_be_removed->data)
      {
         parent = to_be_removed;
         to_be_removed = to_be_removed->left;
      }
      else found = true;
   }

   if (!found) return;

   // to_be_removed contains data

   // If one of the children is empty, use the other

   if (to_be_removed->left == NULL || to_be_removed->right == NULL)
   {
      TreeNode* new_child;
      if (to_be_removed->left == NULL) 
         new_child = to_be_removed->right;
      else 
         new_child = to_be_removed->left;
      
	  if (parent == NULL) // Found in root
         root = new_child;
      else if (parent->left == to_be_removed)
         parent->left = new_child;
      else 
         parent->right = new_child;
      return;
   }
      
   // Neither subtree is empty
   // Find smallest element of the right subtree
   TreeNode* smallest_parent = to_be_removed;
   TreeNode* smallest = to_be_removed->right;
   while (smallest->left != NULL)
   {
      smallest_parent = smallest;
      smallest = smallest->left;
   }

   // smallest contains smallest child in right subtree
       
   // Move contents, unlink child
   to_be_removed->data = smallest->data;
   if (smallest_parent == to_be_removed) 
      smallest_parent->right = smallest->right; 
   else 
      smallest_parent->left = smallest->right; 
}
 
void BinarySearchTree::printLevel(int level) {
    if (root != NULL) {
        root->print_nodesLevel(level); //call the helper funciton in treeNode
    }
}

void BinarySearchTree::postorder(Action* a) {
    if (root != nullptr) root->postorderTraversal(a); //call the helperfunction in treeNode
}